#include "libnm/Device.h"
#include <NetworkManager.h>

libnm::Device::Device( NMDevice* pDevice )
	: pDevice_(pDevice)
{
	//g_object_ref(pDevice_);
}

libnm::Device::~Device()
{
	//g_object_unref(pDevice_);
}

const char* libnm::Device::getIface() const
{
	return nm_device_get_iface(pDevice_);
}

const char* libnm::Device::getDriver() const
{
	return nm_device_get_driver(pDevice_);
}
