#include "libnm/Client.h"
#include <stdexcept>
#include "libnm/RemoteConnection.h"
// #include "libnm/Device.h"

libnm::Client::Client()
{
}

libnm::Client::~Client()
{
}

const char* libnm::Client::getVersion() const
{
	return "1.8.0";
}

std::vector<libnm::RemoteConnection> libnm::Client::getConnections() const
{
	throw std::logic_error("libnm::Client::getConnections() has not been implemented for the mock classes");
	// std::vector<libnm::RemoteConnection> returnValue;
	// return returnValue;
}

std::vector<libnm::Device> libnm::Client::getDevices() const
{
	throw std::logic_error("libnm::Client::getDevices() has not been implemented for the mock classes");
	// std::vector<libnm::Device> returnValue;
	// return returnValue;
}

libnm::RemoteConnection libnm::Client::addConnection( libnm::Connection& connection )
{
	throw std::logic_error("libnm::Client::addConnection() has not been implemented for the mock classes");
}
