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
