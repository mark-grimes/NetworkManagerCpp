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
	std::vector<libnm::RemoteConnection> returnValue;
	return returnValue;
}

std::vector<libnm::Device> libnm::Client::getDevices() const
{
	std::vector<libnm::Device> returnValue;
	returnValue.push_back( libnm::Device(libnm::Device::DeviceType::WIFI,"wlan0","brcmfmac_sdio") );
	return returnValue;
}

libnm::RemoteConnection libnm::Client::addConnection( libnm::Connection& connection )
{
	throw std::logic_error("libnm::Client::addConnection() has not been implemented for the mock classes");
}
