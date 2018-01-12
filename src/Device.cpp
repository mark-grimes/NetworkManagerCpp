#include "libnm/Device.h"
#include <stdexcept>
#include "libnm/DeviceWifi.h"
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

libnm::Device::DeviceType libnm::Device::type() const
{
	if( NM_IS_DEVICE_OLPC_MESH(pDevice_) ) return DeviceType::OLPC;
#ifdef NM_IS_DEVICE_MACSEC
	else if( NM_IS_DEVICE_MACSEC(pDevice_) ) return DeviceType::MACSEC;
#endif
	else if( NM_IS_DEVICE_BRIDGE(pDevice_) ) return DeviceType::BRIDGE;
	else if( NM_IS_DEVICE_ADSL(pDevice_) ) return DeviceType::ADSL;
	else if( NM_IS_DEVICE_INFINIBAND(pDevice_) ) return DeviceType::INFINIBAND;
	else if( NM_IS_DEVICE_MACVLAN(pDevice_) ) return DeviceType::MACVLAN;
	else if( NM_IS_DEVICE_TEAM(pDevice_) ) return DeviceType::TEAM;
	else if( NM_IS_DEVICE_VXLAN(pDevice_) ) return DeviceType::VXLAN;
	else if( NM_IS_DEVICE_MODEM(pDevice_) ) return DeviceType::MODEM;
	else if( NM_IS_DEVICE_VLAN(pDevice_) ) return DeviceType::VLAN;
	else if( NM_IS_DEVICE_BT(pDevice_) ) return DeviceType::BT;
	else if( NM_IS_DEVICE_WIMAX(pDevice_) ) return DeviceType::WIMAX;
	else if( NM_IS_DEVICE_IP_TUNNEL(pDevice_) ) return DeviceType::IP;
	else if( NM_IS_DEVICE_BOND(pDevice_) ) return DeviceType::BOND;
	else if( NM_IS_DEVICE_ETHERNET(pDevice_) ) return DeviceType::ETHERNET;
	else if( NM_IS_DEVICE_TUN(pDevice_) ) return DeviceType::TUN;
	else if( NM_IS_DEVICE_GENERIC(pDevice_) ) return DeviceType::GENERIC;
	else if( NM_IS_DEVICE_WIFI(pDevice_) ) return DeviceType::WIFI;
	else return DeviceType::UNKNOWN;
}

libnm::DeviceWifi libnm::Device::asDeviceWifi()
{
	if( !NM_IS_DEVICE_WIFI(pDevice_) ) throw std::runtime_error("Device::asDeviceWifi called on a non-WIFI device");
	else return libnm::DeviceWifi( reinterpret_cast<NMDeviceWifi*>(pDevice_) );
}

const char* libnm::Device::getIface() const
{
	return nm_device_get_iface(pDevice_);
}

const char* libnm::Device::getDriver() const
{
	return nm_device_get_driver(pDevice_);
}
