#include "libnm/DeviceWifi.h"
#include <stdexcept>
#include "libnm/AccessPoint.h"
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

libnm::AccessPoint libnm::DeviceWifi::getActiveAccessPoint()
{
	NMAccessPoint* pAccessPoint=nm_device_wifi_get_active_access_point( reinterpret_cast<NMDeviceWifi*>(pDevice_) );
	if( pAccessPoint==nullptr ) throw std::runtime_error("libnm::DeviceWifi::getActiveAccessPoint() - no active access point");
	else return libnm::AccessPoint(pAccessPoint);
}

std::vector<libnm::AccessPoint> libnm::DeviceWifi::getAccessPoints() const
{
	std::vector<libnm::AccessPoint> returnValue;

	const GPtrArray* pAccessPoints = nm_device_wifi_get_access_points( reinterpret_cast<NMDeviceWifi*>(pDevice_) );

	for( size_t index=0; index<pAccessPoints->len; ++index )
	{
		returnValue.emplace_back( static_cast<NMAccessPoint*>( g_ptr_array_index( pAccessPoints, index ) ) );
	}

	return returnValue;
}
