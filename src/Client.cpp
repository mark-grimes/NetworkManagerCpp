#include "libnm/Client.h"
#include <stdexcept>
#include <NetworkManager.h>
#include "libnm/RemoteConnection.h"
#include "libnm/ActiveConnection.h"
#include "libnm/AccessPoint.h"
#include "libnm/Device.h"

namespace // Unnamed namespace for things only used in this file
{
	template<class T_ReturnType>
	struct CallbackContext
	{
		bool hasCompleted=false;
		T_ReturnType result;
		GError* pError=nullptr;
		T_ReturnType (*pFinishFunction)( NMClient* pClient, GAsyncResult* pResult, GError** pError );
		static void callback( GObject* pSourceObject, GAsyncResult* pResult, void* pUserData );
		CallbackContext( T_ReturnType (*pFinishFunc)( NMClient*, GAsyncResult*, GError** ) ) : pFinishFunction(pFinishFunc) {}
		~CallbackContext() { if( pError ) g_error_free( pError ); }
	};

	template<class T_ReturnType>
	void CallbackContext<T_ReturnType>::callback( GObject* pSourceObject, GAsyncResult* pResult, void* pUserData )
	{
		::CallbackContext<T_ReturnType>& callbackContext=*reinterpret_cast<::CallbackContext<T_ReturnType>*>(pUserData);
		callbackContext.hasCompleted=true;
		callbackContext.result=(*callbackContext.pFinishFunction)( NM_CLIENT(pSourceObject), pResult, &callbackContext.pError );
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
	::CallbackContext<NMRemoteConnection*> callbackContext( &nm_client_add_connection_finish ); // wait for callback to complete so okay to use the stack
	nm_client_add_connection_async( pClient_, connection.native_handle(), false, nullptr, &::CallbackContext<NMRemoteConnection*>::callback, &callbackContext );
	// I haven't implemented a way to handle asynchronous methods yet, so just wait on the result here.
	while( !callbackContext.hasCompleted ) g_main_context_iteration( nullptr, true );

	if( callbackContext.pError ) throw std::runtime_error( callbackContext.pError->message );
	else return libnm::RemoteConnection( callbackContext.result, true );
}

libnm::ActiveConnection libnm::Client::activateConnection( libnm::Connection& connection )
{
	::CallbackContext<NMActiveConnection*> callbackContext( &nm_client_activate_connection_finish ); // wait for callback to complete so okay to use the stack
	nm_client_activate_connection_async( pClient_, connection.native_handle(), nullptr, nullptr, nullptr, &::CallbackContext<NMActiveConnection*>::callback, &callbackContext );
	// I haven't implemented a way to handle asynchronous methods yet, so just wait on the result here.
	while( !callbackContext.hasCompleted ) g_main_context_iteration( nullptr, true );

	if( callbackContext.pError ) throw std::runtime_error( callbackContext.pError->message );
	else return libnm::ActiveConnection( callbackContext.result, true );
}

libnm::ActiveConnection libnm::Client::activateConnection( libnm::Connection& connection, libnm::AccessPoint& accessPoint )
{
	::CallbackContext<NMActiveConnection*> callbackContext( &nm_client_activate_connection_finish ); // wait for callback to complete so okay to use the stack
	nm_client_activate_connection_async( pClient_, connection.native_handle(), nullptr, nm_object_get_path(reinterpret_cast<NMObject*>(accessPoint.native_handle())), nullptr, &::CallbackContext<NMActiveConnection*>::callback, &callbackContext );
	// I haven't implemented a way to handle asynchronous methods yet, so just wait on the result here.
	while( !callbackContext.hasCompleted ) g_main_context_iteration( nullptr, true );

	if( callbackContext.pError ) throw std::runtime_error( callbackContext.pError->message );
	else return libnm::ActiveConnection( callbackContext.result, true );
}
