#include "libnm/RemoteConnection.h"
#include <stdexcept>

libnm::RemoteConnection::~RemoteConnection()
{
}

bool libnm::RemoteConnection::save() const
{
	throw std::logic_error("libnm::RemoteConnection::save() has not been implemented for the mock classes");
}

bool libnm::RemoteConnection::deleteConnection()
{
	throw std::logic_error("libnm::RemoteConnection::deleteConnection() has not been implemented for the mock classes");
}
