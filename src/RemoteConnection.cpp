#include "libnm/RemoteConnection.h"

libnm::RemoteConnection::RemoteConnection( NMRemoteConnection* pRemoteConnection )
	: Connection( reinterpret_cast<NMConnection*>(pRemoteConnection) )
{
}

libnm::RemoteConnection::~RemoteConnection()
{
}
