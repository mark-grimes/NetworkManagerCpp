#include "libnm/Client.h"
#include <stdexcept>
#include <NetworkManager.h>
#include "libnm/RemoteConnection.h"
#include "libnm/Device.h"

namespace // Unnamed namespace for things only used in this file
{
	template<class T_ReturnType>
	struct CallbackContext
	{
		bool hasCompleted=false;
		T_ReturnType result;
		GError* pError=nullptr;
		static void callback( GObject* pSourceObject, GAsyncResult* pResult, void* pUserData );
		~CallbackContext() { if( pError ) g_error_free( pError ); }
	};

	template<>
	void CallbackContext<NMRemoteConnection*>::callback( GObject* pSourceObject, GAsyncResult* pResult, void* pUserData )
	{
		::CallbackContext<NMRemoteConnection*>& callbackContext=*reinterpret_cast<::CallbackContext<NMRemoteConnection*>*>(pUserData);
		callbackContext.hasCompleted=true;
		callbackContext.result=nm_client_add_connection_finish( NM_CLIENT(pSourceObject), pResult, &callbackContext.pError );
	}

} // end of the unnamed namespace

libnm::Client::Client()
{
	GError* pError=nullptr;
	pClient_=nm_client_new( NULL, &pError );
	if( pClient_==nullptr ) throw std::runtime_error(std::string("Unable to initialise NMClient:")+pError->message);
	if( !nm_client_get_nm_running(pClient_) )
	{
		g_object_unref(pClient_);
		throw std::runtime_error("Unable to initialise NMClient: networking is not enabled");
	}
}

libnm::Client::Client( const libnm::Client& other )
{
	pClient_=other.pClient_;
	if( pClient_ ) g_object_ref(pClient_);
}

libnm::Client::Client( libnm::Client&& other )
{
	pClient_=other.pClient_;
	other.pClient_=nullptr;
}

libnm::Client& libnm::Client::operator=( const libnm::Client& other )
{
	pClient_=other.pClient_;
	if( pClient_ ) g_object_ref(pClient_);
	return *this;
}

libnm::Client& libnm::Client::operator=( libnm::Client&& other )
{
	pClient_=other.pClient_;
	other.pClient_=nullptr;
	return *this;
}

libnm::Client::~Client()
{
	if( pClient_ ) g_object_unref(pClient_);
}

const char* libnm::Client::getVersion() const
{
	return nm_client_get_version(pClient_);
}

std::vector<libnm::RemoteConnection> libnm::Client::getConnections() const
{
	std::vector<libnm::RemoteConnection> returnValue;

	const GPtrArray *pRemoteConnections = nm_client_get_connections(pClient_);
	for( size_t index=0; index<pRemoteConnections->len; ++index )
	{
		returnValue.push_back( libnm::RemoteConnection( reinterpret_cast<NMRemoteConnection*>(pRemoteConnections->pdata[index]) ) );
	}

	return returnValue;
}

std::vector<libnm::Device> libnm::Client::getDevices() const
{
	std::vector<libnm::Device> returnValue;

	const GPtrArray *pDevices = nm_client_get_devices(pClient_);
	for( size_t index=0; index<pDevices->len; ++index )
	{
		returnValue.push_back( libnm::Device( static_cast<NMDevice*>( g_ptr_array_index( pDevices, index ) ) ) );
	}

	return returnValue;
}

libnm::RemoteConnection libnm::Client::addConnection( libnm::Connection& connection )
{
	::CallbackContext<NMRemoteConnection*> callbackContext; // wait for addConnectionCallback to complete so okay to use the stack
	nm_client_add_connection_async( pClient_, connection.native_handle(), false, nullptr, &::CallbackContext<NMRemoteConnection*>::callback, &callbackContext );
	// I haven't implemented a way to handle asynchronous methods yet, so just wait on the result here.
	while( !callbackContext.hasCompleted ) g_main_context_iteration( nullptr, true );

	if( callbackContext.pError ) throw std::runtime_error( callbackContext.pError->message );
	else return libnm::RemoteConnection( callbackContext.result );
}
