#include "libnm/Device.h"
#include <stdexcept>
#include "libnm/DeviceWifi.h"


libnm::Device::~Device()
{
}

libnm::Device::DeviceType libnm::Device::type() const
{
	return type_;
}

libnm::DeviceWifi libnm::Device::asDeviceWifi()
{
	return libnm::DeviceWifi( type_, interface_, driver_ );
}

const char* libnm::Device::getIface() const
{
	return interface_.c_str();
}

const char* libnm::Device::getDriver() const
{
	return driver_.c_str();
}
