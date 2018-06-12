#include "libnm/ActiveConnection.h"
#include <stdexcept>

NMActiveConnection* libnm::ActiveConnection::native_handle()
{
	throw std::logic_error("libnm::ActiveConnection::native_handle() has not been implemented for the mock classes");
}

const NMActiveConnection* libnm::ActiveConnection::native_handle() const
{
	throw std::logic_error("libnm::ActiveConnection::native_handle() has not been implemented for the mock classes");
}

const char* libnm::ActiveConnection::getUuid() const
{
	throw std::logic_error("libnm::ActiveConnection::getUuid() has not been implemented for the mock classes");
}

const char* libnm::ActiveConnection::getId() const
{
	throw std::logic_error("libnm::ActiveConnection::getId() has not been implemented for the mock classes");
}
