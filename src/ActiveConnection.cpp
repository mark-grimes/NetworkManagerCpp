#include "libnm/ActiveConnection.h"
#include <stdexcept>
#include "libnm/Setting.h"
#include <NetworkManager.h>

libnm::ActiveConnection::ActiveConnection( NMActiveConnection* pActiveConnection, bool adopt )
	: pActiveConnection_(pActiveConnection)
{
	if( pActiveConnection_ && !adopt ) g_object_ref(pActiveConnection_);
}

libnm::ActiveConnection::ActiveConnection( const libnm::ActiveConnection& other )
{
	pActiveConnection_=other.pActiveConnection_;
	if( pActiveConnection_ ) g_object_ref(pActiveConnection_);
}

libnm::ActiveConnection::ActiveConnection( libnm::ActiveConnection&& other )
{
	pActiveConnection_=other.pActiveConnection_;
	other.pActiveConnection_=nullptr;
}

libnm::ActiveConnection& libnm::ActiveConnection::operator=( const libnm::ActiveConnection& other )
{
	pActiveConnection_=other.pActiveConnection_;
	if( pActiveConnection_ ) g_object_ref(pActiveConnection_);
	return *this;
}

libnm::ActiveConnection& libnm::ActiveConnection::operator=( libnm::ActiveConnection&& other )
{
	pActiveConnection_=other.pActiveConnection_;
	other.pActiveConnection_=nullptr;
	return *this;
}

libnm::ActiveConnection::~ActiveConnection()
{
	if( pActiveConnection_ ) g_object_unref(pActiveConnection_);
}

NMActiveConnection* libnm::ActiveConnection::native_handle()
{
	return pActiveConnection_;
}

const NMActiveConnection* libnm::ActiveConnection::native_handle() const
{
	return pActiveConnection_;
}

const char* libnm::ActiveConnection::getUuid() const
{
	if( !pActiveConnection_ ) throw std::runtime_error("libnm::ActiveConnection::getUuid() called on invalid ActiveConnection");
	return nm_active_connection_get_uuid(pActiveConnection_);
}

const char* libnm::ActiveConnection::getId() const
{
	if( !pActiveConnection_ ) throw std::runtime_error("libnm::ActiveConnection::getId() called on invalid ActiveConnection");
	return nm_active_connection_get_id(pActiveConnection_);
}
