#include "libnm/DeviceWifi.h"
#include <NetworkManager.h>

libnm::DeviceWifi::DeviceWifi( NMDeviceWifi* pDeviceWifi )
	: Device( reinterpret_cast<NMDevice*>(pDeviceWifi) )
{
	//g_object_ref(pDeviceWifi_);
}

libnm::DeviceWifi::~DeviceWifi()
{
	//g_object_unref(pDeviceWifi_);
}
