#include "libnm/Connection.h"
#include <NetworkManager.h>

libnm::Connection::Connection( NMConnection* pConnection )
	: pConnection_(pConnection)
{
	//g_object_ref(pConnection_);
}

libnm::Connection::~Connection()
{
	//g_object_unref(pConnection_);
}

const char* libnm::Connection::getId() const
{
	return nm_connection_get_id(pConnection_);
}
