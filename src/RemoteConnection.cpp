#include "libnm/RemoteConnection.h"
#include <stdexcept>
#include <NetworkManager.h>

libnm::RemoteConnection::RemoteConnection( NMRemoteConnection* pRemoteConnection, bool adopt )
	: Connection( reinterpret_cast<NMConnection*>(pRemoteConnection), adopt )
{
}

libnm::RemoteConnection::~RemoteConnection()
{
}

bool libnm::RemoteConnection::deleteConnection()
{
	GError* pError=nullptr;
	bool result=nm_remote_connection_delete( reinterpret_cast<NMRemoteConnection*>(pConnection_), nullptr, &pError );
	if( pError )
	{
		std::string message=pError->message;
		g_error_free( pError );
		throw std::runtime_error(message);
	}
	return result;
}
