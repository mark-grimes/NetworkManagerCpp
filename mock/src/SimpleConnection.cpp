#include "libnm/SimpleConnection.h"

libnm::SimpleConnection::SimpleConnection( const std::string& name, libnm::SimpleConnection::ConnectionType type )
	: Connection( "Some UUID", name )
{
}

libnm::SimpleConnection::~SimpleConnection()
{
}
