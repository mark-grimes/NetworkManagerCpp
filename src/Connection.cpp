#include "libnm/Connection.h"
#include <NetworkManager.h>

libnm::Connection::Connection( NMConnection* pConnection )
	: pConnection_(pConnection)
{
	g_object_ref(pConnection_);
}

libnm::Connection::Connection( const libnm::Connection& other )
{
	pConnection_=other.pConnection_;
	if( pConnection_ ) g_object_ref(pConnection_);
}

libnm::Connection::Connection( libnm::Connection&& other )
{
	pConnection_=other.pConnection_;
	other.pConnection_=nullptr;
}

libnm::Connection& libnm::Connection::operator=( const libnm::Connection& other )
{
	pConnection_=other.pConnection_;
	if( pConnection_ ) g_object_ref(pConnection_);
	return *this;
}

libnm::Connection& libnm::Connection::operator=( libnm::Connection&& other )
{
	pConnection_=other.pConnection_;
	other.pConnection_=nullptr;
	return *this;
}

libnm::Connection::~Connection()
{
	if( pConnection_ ) g_object_unref(pConnection_);
}

const char* libnm::Connection::getId() const
{
	return nm_connection_get_id(pConnection_);
}
