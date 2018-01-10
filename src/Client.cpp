#include "libnm/Client.h"
#include <stdexcept>
#include <NetworkManager.h>
#include "libnm/RemoteConnection.h"

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

libnm::Client::~Client()
{
	g_object_unref(pClient_);
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
