#include "libnm/Connection.h"
#include <stdexcept>


libnm::Connection::~Connection()
{
}

NMConnection* libnm::Connection::native_handle()
{
	throw std::logic_error("libnm::Connection::native_handle() has not been implemented for the mock classes");
}

const NMConnection* libnm::Connection::native_handle() const
{
	throw std::logic_error("libnm::Connection::native_handle() has not been implemented for the mock classes");
}

void libnm::Connection::addSetting( libnm::Setting&& setting )
{
	settings_.push_back( std::move(setting) );
}

const char* libnm::Connection::getUuid() const
{
	return uuid_.c_str();
}

const char* libnm::Connection::getId() const
{
	return id_.c_str();
}
