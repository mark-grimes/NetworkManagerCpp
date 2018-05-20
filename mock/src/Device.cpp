#include "libnm/Device.h"
#include <stdexcept>
#include "libnm/DeviceWifi.h"


libnm::Device::~Device()
{
}

libnm::Device::DeviceType libnm::Device::type() const
{
	return DeviceType::WIFI;
}

libnm::DeviceWifi libnm::Device::asDeviceWifi()
{
	throw std::runtime_error("Device::asDeviceWifi called on a non-WIFI device");
}

const char* libnm::Device::getIface() const
{
	return "wlan0";
}

const char* libnm::Device::getDriver() const
{
	return "brcmfmac_sdio";
}
