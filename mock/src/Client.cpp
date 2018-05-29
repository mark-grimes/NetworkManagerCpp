#include "libnm/Client.h"
#include <stdexcept>
#include "libnm/RemoteConnection.h"
#include "libnm/Device.h"

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
	return connections_;
}

std::vector<libnm::Device> libnm::Client::getDevices() const
{
	return devices_;
}

libnm::RemoteConnection libnm::Client::addConnection( libnm::Connection& connection )
{
	throw std::logic_error("libnm::Client::addConnection() has not been implemented for the mock classes");
}

void libnm::Client::mock_addDevice( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver )
{
	devices_.push_back( libnm::Device(type,interface,driver) );
}

libnm::Device& libnm::Client::mock_getDevice( size_t index )
{
	return devices_.at(index);
}

void libnm::Client::mock_addConnection( const std::string& uuid, const std::string& id )
{
	connections_.push_back( libnm::RemoteConnection(uuid,id) );
}
