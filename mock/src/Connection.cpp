#include "libnm/Connection.h"
#include <stdexcept>


libnm::Connection::~Connection()
{
}

NMConnection* libnm::Connection::native_handle()
{
	return nullptr;
}

const NMConnection* libnm::Connection::native_handle() const
{
	return nullptr;
}

void libnm::Connection::addSetting( libnm::Setting&& setting )
{
	throw std::logic_error("libnm::Connection::addSetting() has not been implemented for the mock classes");
}

const char* libnm::Connection::getUuid() const
{
	return uuid_.c_str();
}

const char* libnm::Connection::getId() const
{
	return id_.c_str();
}
