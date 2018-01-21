#include "libnm/Connection.h"
#include "libnm/Setting.h"
#include <NetworkManager.h>

libnm::Connection::Connection( NMConnection* pConnection, bool adopt )
	: pConnection_(pConnection)
{
	if( pConnection_ && !adopt ) g_object_ref(pConnection_);
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

NMConnection* libnm::Connection::native_handle()
{
	return pConnection_;
}

const NMConnection* libnm::Connection::native_handle() const
{
	return pConnection_;
}

void libnm::Connection::addSetting( libnm::Setting&& setting )
{
	nm_connection_add_setting( pConnection_, setting.native_handle() );
	// The connection has taken ownership, so need to invaildate the setting object
	setting.invalidate();
}

const char* libnm::Connection::getUuid() const
{
	return nm_connection_get_uuid(pConnection_);
}

const char* libnm::Connection::getId() const
{
	return nm_connection_get_id(pConnection_);
}
