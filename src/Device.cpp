#include "libnm/Device.h"
#include <stdexcept>
#include <iostream>
#include "libnm/DeviceWifi.h"
#include "libnm/ActiveConnection.h"
#include <NetworkManager.h>

std::ostream& operator<<( std::ostream& stream, libnm::Device::State state )
{
	switch( state )
	{
		case libnm::Device::State::UNKNOWN: stream << "Device::State::UNKNOWN"; break;
		case libnm::Device::State::UNMANAGED: stream << "Device::State::UNMANAGED"; break;
		case libnm::Device::State::UNAVAILABLE: stream << "Device::State::UNAVAILABLE"; break;
		case libnm::Device::State::DISCONNECTED: stream << "Device::State::DISCONNECTED"; break;
		case libnm::Device::State::PREPARE: stream << "Device::State::PREPARE"; break;
		case libnm::Device::State::CONFIG: stream << "Device::State::CONFIG"; break;
		case libnm::Device::State::NEED_AUTH: stream << "Device::State::NEED_AUTH"; break;
		case libnm::Device::State::IP_CONFIG: stream << "Device::State::IP_CONFIG"; break;
		case libnm::Device::State::IP_CHECK: stream << "Device::State::IP_CHECK"; break;
		case libnm::Device::State::SECONDARIES: stream << "Device::State::SECONDARIES"; break;
		case libnm::Device::State::ACTIVATED: stream << "Device::State::ACTIVATED"; break;
		case libnm::Device::State::DEACTIVATING: stream << "Device::State::DEACTIVATING"; break;
		case libnm::Device::State::FAILED: stream << "Device::State::FAILED"; break;
	}
	return stream;
}

std::ostream& operator<<( std::ostream& stream, libnm::Device::StateReason reason )
{
	switch( reason )
	{
		case libnm::Device::StateReason::NONE: stream << "Device::StateReason::NONE"; break;
		case libnm::Device::StateReason::UNKNOWN: stream << "Device::StateReason::UNKNOWN"; break;
		case libnm::Device::StateReason::NOW_MANAGED: stream << "Device::StateReason::NOW_MANAGED"; break;
		case libnm::Device::StateReason::NOW_UNMANAGED: stream << "Device::StateReason::NOW_UNMANAGED"; break;
		case libnm::Device::StateReason::CONFIG_FAILED: stream << "Device::StateReason::CONFIG_FAILED"; break;
		case libnm::Device::StateReason::IP_CONFIG_UNAVAILABLE: stream << "Device::StateReason::IP_CONFIG_UNAVAILABLE"; break;
		case libnm::Device::StateReason::IP_CONFIG_EXPIRED: stream << "Device::StateReason::IP_CONFIG_EXPIRED"; break;
		case libnm::Device::StateReason::NO_SECRETS: stream << "Device::StateReason::NO_SECRETS"; break;
		case libnm::Device::StateReason::SUPPLICANT_DISCONNECT: stream << "Device::StateReason::SUPPLICANT_DISCONNECT"; break;
		case libnm::Device::StateReason::SUPPLICANT_CONFIG_FAILED: stream << "Device::StateReason::SUPPLICANT_CONFIG_FAILED"; break;
		case libnm::Device::StateReason::SUPPLICANT_FAILED: stream << "Device::StateReason::SUPPLICANT_FAILED"; break;
		case libnm::Device::StateReason::SUPPLICANT_TIMEOUT: stream << "Device::StateReason::SUPPLICANT_TIMEOUT"; break;
		case libnm::Device::StateReason::PPP_START_FAILED: stream << "Device::StateReason::PPP_START_FAILED"; break;
		case libnm::Device::StateReason::PPP_DISCONNECT: stream << "Device::StateReason::PPP_DISCONNECT"; break;
		case libnm::Device::StateReason::PPP_FAILED: stream << "Device::StateReason::PPP_FAILED"; break;
		case libnm::Device::StateReason::DHCP_START_FAILED: stream << "Device::StateReason::DHCP_START_FAILED"; break;
		case libnm::Device::StateReason::DHCP_ERROR: stream << "Device::StateReason::DHCP_ERROR"; break;
		case libnm::Device::StateReason::DHCP_FAILED: stream << "Device::StateReason::DHCP_FAILED"; break;
		case libnm::Device::StateReason::SHARED_START_FAILED: stream << "Device::StateReason::SHARED_START_FAILED"; break;
		case libnm::Device::StateReason::SHARED_FAILED: stream << "Device::StateReason::SHARED_FAILED"; break;
		case libnm::Device::StateReason::AUTOIP_START_FAILED: stream << "Device::StateReason::AUTOIP_START_FAILED"; break;
		case libnm::Device::StateReason::AUTOIP_ERROR: stream << "Device::StateReason::AUTOIP_ERROR"; break;
		case libnm::Device::StateReason::AUTOIP_FAILED: stream << "Device::StateReason::AUTOIP_FAILED"; break;
		case libnm::Device::StateReason::MODEM_BUSY: stream << "Device::StateReason::MODEM_BUSY"; break;
		case libnm::Device::StateReason::MODEM_NO_DIAL_TONE: stream << "Device::StateReason::MODEM_NO_DIAL_TONE"; break;
		case libnm::Device::StateReason::MODEM_NO_CARRIER: stream << "Device::StateReason::MODEM_NO_CARRIER"; break;
		case libnm::Device::StateReason::MODEM_DIAL_TIMEOUT: stream << "Device::StateReason::MODEM_DIAL_TIMEOUT"; break;
		case libnm::Device::StateReason::MODEM_DIAL_FAILED: stream << "Device::StateReason::MODEM_DIAL_FAILED"; break;
		case libnm::Device::StateReason::MODEM_INIT_FAILED: stream << "Device::StateReason::MODEM_INIT_FAILED"; break;
		case libnm::Device::StateReason::GSM_APN_FAILED: stream << "Device::StateReason::GSM_APN_FAILED"; break;
		case libnm::Device::StateReason::GSM_REGISTRATION_NOT_SEARCHING: stream << "Device::StateReason::GSM_REGISTRATION_NOT_SEARCHING"; break;
		case libnm::Device::StateReason::GSM_REGISTRATION_DENIED: stream << "Device::StateReason::GSM_REGISTRATION_DENIED"; break;
		case libnm::Device::StateReason::GSM_REGISTRATION_TIMEOUT: stream << "Device::StateReason::GSM_REGISTRATION_TIMEOUT"; break;
		case libnm::Device::StateReason::GSM_REGISTRATION_FAILED: stream << "Device::StateReason::GSM_REGISTRATION_FAILED"; break;
		case libnm::Device::StateReason::GSM_PIN_CHECK_FAILED: stream << "Device::StateReason::GSM_PIN_CHECK_FAILED"; break;
		case libnm::Device::StateReason::FIRMWARE_MISSING: stream << "Device::StateReason::FIRMWARE_MISSING"; break;
		case libnm::Device::StateReason::REMOVED: stream << "Device::StateReason::REMOVED"; break;
		case libnm::Device::StateReason::SLEEPING: stream << "Device::StateReason::SLEEPING"; break;
		case libnm::Device::StateReason::CONNECTION_REMOVED: stream << "Device::StateReason::CONNECTION_REMOVED"; break;
		case libnm::Device::StateReason::USER_REQUESTED: stream << "Device::StateReason::USER_REQUESTED"; break;
		case libnm::Device::StateReason::CARRIER: stream << "Device::StateReason::CARRIER"; break;
		case libnm::Device::StateReason::CONNECTION_ASSUMED: stream << "Device::StateReason::CONNECTION_ASSUMED"; break;
		case libnm::Device::StateReason::SUPPLICANT_AVAILABLE: stream << "Device::StateReason::SUPPLICANT_AVAILABLE"; break;
		case libnm::Device::StateReason::MODEM_NOT_FOUND: stream << "Device::StateReason::MODEM_NOT_FOUND"; break;
		case libnm::Device::StateReason::BT_FAILED: stream << "Device::StateReason::BT_FAILED"; break;
		case libnm::Device::StateReason::GSM_SIM_NOT_INSERTED: stream << "Device::StateReason::GSM_SIM_NOT_INSERTED"; break;
		case libnm::Device::StateReason::GSM_SIM_PIN_REQUIRED: stream << "Device::StateReason::GSM_SIM_PIN_REQUIRED"; break;
		case libnm::Device::StateReason::GSM_SIM_PUK_REQUIRED: stream << "Device::StateReason::GSM_SIM_PUK_REQUIRED"; break;
		case libnm::Device::StateReason::GSM_SIM_WRONG: stream << "Device::StateReason::GSM_SIM_WRONG"; break;
		case libnm::Device::StateReason::INFINIBAND_MODE: stream << "Device::StateReason::INFINIBAND_MODE"; break;
		case libnm::Device::StateReason::DEPENDENCY_FAILED: stream << "Device::StateReason::DEPENDENCY_FAILED"; break;
		case libnm::Device::StateReason::BR2684_FAILED: stream << "Device::StateReason::BR2684_FAILED"; break;
		case libnm::Device::StateReason::MODEM_MANAGER_UNAVAILABLE: stream << "Device::StateReason::MODEM_MANAGER_UNAVAILABLE"; break;
		case libnm::Device::StateReason::SSID_NOT_FOUND: stream << "Device::StateReason::SSID_NOT_FOUND"; break;
		case libnm::Device::StateReason::SECONDARY_CONNECTION_FAILED: stream << "Device::StateReason::SECONDARY_CONNECTION_FAILED"; break;
		case libnm::Device::StateReason::DCB_FCOE_FAILED: stream << "Device::StateReason::DCB_FCOE_FAILED"; break;
		case libnm::Device::StateReason::TEAMD_CONTROL_FAILED: stream << "Device::StateReason::TEAMD_CONTROL_FAILED"; break;
		case libnm::Device::StateReason::MODEM_FAILED: stream << "Device::StateReason::MODEM_FAILED"; break;
		case libnm::Device::StateReason::MODEM_AVAILABLE: stream << "Device::StateReason::MODEM_AVAILABLE"; break;
		case libnm::Device::StateReason::SIM_PIN_INCORRECT: stream << "Device::StateReason::SIM_PIN_INCORRECT"; break;
		case libnm::Device::StateReason::NEW_ACTIVATION: stream << "Device::StateReason::NEW_ACTIVATION"; break;
		case libnm::Device::StateReason::PARENT_CHANGED: stream << "Device::StateReason::PARENT_CHANGED"; break;
		case libnm::Device::StateReason::PARENT_MANAGED_CHANGED: stream << "Device::StateReason::PARENT_MANAGED_CHANGED"; break;
		case libnm::Device::StateReason::OVSDB_FAILED: stream << "Device::StateReason::OVSDB_FAILED"; break;
		case libnm::Device::StateReason::IP_ADDRESS_DUPLICATE: stream << "Device::StateReason::IP_ADDRESS_DUPLICATE"; break;
		case libnm::Device::StateReason::IP_METHOD_UNSUPPORTED: stream << "Device::StateReason::IP_METHOD_UNSUPPORTED"; break;
	}
	return stream;
}

libnm::Device::Device( NMDevice* pDevice )
	: pDevice_(pDevice)
{
	g_object_ref(pDevice_);
}

libnm::Device::Device( const libnm::Device& other )
{
	pDevice_=other.pDevice_;
	g_object_ref(pDevice_);
}

libnm::Device::Device( libnm::Device&& other )
{
	pDevice_=other.pDevice_;
	other.pDevice_=nullptr;
}

libnm::Device& libnm::Device::operator=( const libnm::Device& other )
{
	pDevice_=other.pDevice_;
	g_object_ref(pDevice_);
	return *this;
}

libnm::Device& libnm::Device::operator=( libnm::Device&& other )
{
	pDevice_=other.pDevice_;
	other.pDevice_=nullptr;
	return *this;
}

libnm::Device::~Device()
{
	if( pDevice_ ) g_object_unref(pDevice_);
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

const char* libnm::Device::getIPIface() const
{
	return nm_device_get_ip_iface(pDevice_);
}

libnm::Device::State libnm::Device::getState() const
{
	auto state=nm_device_get_state(pDevice_);
	switch( state )
	{
		case NM_DEVICE_STATE_UNKNOWN: return Device::State::UNKNOWN;
		case NM_DEVICE_STATE_UNMANAGED: return Device::State::UNMANAGED;
		case NM_DEVICE_STATE_UNAVAILABLE: return Device::State::UNAVAILABLE;
		case NM_DEVICE_STATE_DISCONNECTED: return Device::State::DISCONNECTED;
		case NM_DEVICE_STATE_PREPARE: return Device::State::PREPARE;
		case NM_DEVICE_STATE_CONFIG: return Device::State::CONFIG;
		case NM_DEVICE_STATE_NEED_AUTH: return Device::State::NEED_AUTH;
		case NM_DEVICE_STATE_IP_CONFIG: return Device::State::IP_CONFIG;
		case NM_DEVICE_STATE_IP_CHECK: return Device::State::IP_CHECK;
		case NM_DEVICE_STATE_SECONDARIES: return Device::State::SECONDARIES;
		case NM_DEVICE_STATE_ACTIVATED: return Device::State::ACTIVATED;
		case NM_DEVICE_STATE_DEACTIVATING: return Device::State::DEACTIVATING;
		case NM_DEVICE_STATE_FAILED: return Device::State::FAILED;
		default: throw std::runtime_error("libnm::Device::getState() got unexpected state value "+std::to_string(state));
	}
}

libnm::Device::StateReason libnm::Device::getStateReason() const
{
	auto reason=nm_device_get_state_reason(pDevice_);
	switch( reason )
	{
		case NM_DEVICE_STATE_REASON_NONE: return Device::StateReason::NONE;
		case NM_DEVICE_STATE_REASON_UNKNOWN: return Device::StateReason::UNKNOWN;
		case NM_DEVICE_STATE_REASON_NOW_MANAGED: return Device::StateReason::NOW_MANAGED;
		case NM_DEVICE_STATE_REASON_NOW_UNMANAGED: return Device::StateReason::NOW_UNMANAGED;
		case NM_DEVICE_STATE_REASON_CONFIG_FAILED: return Device::StateReason::CONFIG_FAILED;
		case NM_DEVICE_STATE_REASON_IP_CONFIG_UNAVAILABLE: return Device::StateReason::IP_CONFIG_UNAVAILABLE;
		case NM_DEVICE_STATE_REASON_IP_CONFIG_EXPIRED: return Device::StateReason::IP_CONFIG_EXPIRED;
		case NM_DEVICE_STATE_REASON_NO_SECRETS: return Device::StateReason::NO_SECRETS;
		case NM_DEVICE_STATE_REASON_SUPPLICANT_DISCONNECT: return Device::StateReason::SUPPLICANT_DISCONNECT;
		case NM_DEVICE_STATE_REASON_SUPPLICANT_CONFIG_FAILED: return Device::StateReason::SUPPLICANT_CONFIG_FAILED;
		case NM_DEVICE_STATE_REASON_SUPPLICANT_FAILED: return Device::StateReason::SUPPLICANT_FAILED;
		case NM_DEVICE_STATE_REASON_SUPPLICANT_TIMEOUT: return Device::StateReason::SUPPLICANT_TIMEOUT;
		case NM_DEVICE_STATE_REASON_PPP_START_FAILED: return Device::StateReason::PPP_START_FAILED;
		case NM_DEVICE_STATE_REASON_PPP_DISCONNECT: return Device::StateReason::PPP_DISCONNECT;
		case NM_DEVICE_STATE_REASON_PPP_FAILED: return Device::StateReason::PPP_FAILED;
		case NM_DEVICE_STATE_REASON_DHCP_START_FAILED: return Device::StateReason::DHCP_START_FAILED;
		case NM_DEVICE_STATE_REASON_DHCP_ERROR: return Device::StateReason::DHCP_ERROR;
		case NM_DEVICE_STATE_REASON_DHCP_FAILED: return Device::StateReason::DHCP_FAILED;
		case NM_DEVICE_STATE_REASON_SHARED_START_FAILED: return Device::StateReason::SHARED_START_FAILED;
		case NM_DEVICE_STATE_REASON_SHARED_FAILED: return Device::StateReason::SHARED_FAILED;
		case NM_DEVICE_STATE_REASON_AUTOIP_START_FAILED: return Device::StateReason::AUTOIP_START_FAILED;
		case NM_DEVICE_STATE_REASON_AUTOIP_ERROR: return Device::StateReason::AUTOIP_ERROR;
		case NM_DEVICE_STATE_REASON_AUTOIP_FAILED: return Device::StateReason::AUTOIP_FAILED;
		case NM_DEVICE_STATE_REASON_MODEM_BUSY: return Device::StateReason::MODEM_BUSY;
		case NM_DEVICE_STATE_REASON_MODEM_NO_DIAL_TONE: return Device::StateReason::MODEM_NO_DIAL_TONE;
		case NM_DEVICE_STATE_REASON_MODEM_NO_CARRIER: return Device::StateReason::MODEM_NO_CARRIER;
		case NM_DEVICE_STATE_REASON_MODEM_DIAL_TIMEOUT: return Device::StateReason::MODEM_DIAL_TIMEOUT;
		case NM_DEVICE_STATE_REASON_MODEM_DIAL_FAILED: return Device::StateReason::MODEM_DIAL_FAILED;
		case NM_DEVICE_STATE_REASON_MODEM_INIT_FAILED: return Device::StateReason::MODEM_INIT_FAILED;
		case NM_DEVICE_STATE_REASON_GSM_APN_FAILED: return Device::StateReason::GSM_APN_FAILED;
		case NM_DEVICE_STATE_REASON_GSM_REGISTRATION_NOT_SEARCHING: return Device::StateReason::GSM_REGISTRATION_NOT_SEARCHING;
		case NM_DEVICE_STATE_REASON_GSM_REGISTRATION_DENIED: return Device::StateReason::GSM_REGISTRATION_DENIED;
		case NM_DEVICE_STATE_REASON_GSM_REGISTRATION_TIMEOUT: return Device::StateReason::GSM_REGISTRATION_TIMEOUT;
		case NM_DEVICE_STATE_REASON_GSM_REGISTRATION_FAILED: return Device::StateReason::GSM_REGISTRATION_FAILED;
		case NM_DEVICE_STATE_REASON_GSM_PIN_CHECK_FAILED: return Device::StateReason::GSM_PIN_CHECK_FAILED;
		case NM_DEVICE_STATE_REASON_FIRMWARE_MISSING: return Device::StateReason::FIRMWARE_MISSING;
		case NM_DEVICE_STATE_REASON_REMOVED: return Device::StateReason::REMOVED;
		case NM_DEVICE_STATE_REASON_SLEEPING: return Device::StateReason::SLEEPING;
		case NM_DEVICE_STATE_REASON_CONNECTION_REMOVED: return Device::StateReason::CONNECTION_REMOVED;
		case NM_DEVICE_STATE_REASON_USER_REQUESTED: return Device::StateReason::USER_REQUESTED;
		case NM_DEVICE_STATE_REASON_CARRIER: return Device::StateReason::CARRIER;
		case NM_DEVICE_STATE_REASON_CONNECTION_ASSUMED: return Device::StateReason::CONNECTION_ASSUMED;
		case NM_DEVICE_STATE_REASON_SUPPLICANT_AVAILABLE: return Device::StateReason::SUPPLICANT_AVAILABLE;
		case NM_DEVICE_STATE_REASON_MODEM_NOT_FOUND: return Device::StateReason::MODEM_NOT_FOUND;
		case NM_DEVICE_STATE_REASON_BT_FAILED: return Device::StateReason::BT_FAILED;
		case NM_DEVICE_STATE_REASON_GSM_SIM_NOT_INSERTED: return Device::StateReason::GSM_SIM_NOT_INSERTED;
		case NM_DEVICE_STATE_REASON_GSM_SIM_PIN_REQUIRED: return Device::StateReason::GSM_SIM_PIN_REQUIRED;
		case NM_DEVICE_STATE_REASON_GSM_SIM_PUK_REQUIRED: return Device::StateReason::GSM_SIM_PUK_REQUIRED;
		case NM_DEVICE_STATE_REASON_GSM_SIM_WRONG: return Device::StateReason::GSM_SIM_WRONG;
		case NM_DEVICE_STATE_REASON_INFINIBAND_MODE: return Device::StateReason::INFINIBAND_MODE;
		case NM_DEVICE_STATE_REASON_DEPENDENCY_FAILED: return Device::StateReason::DEPENDENCY_FAILED;
		case NM_DEVICE_STATE_REASON_BR2684_FAILED: return Device::StateReason::BR2684_FAILED;
		case NM_DEVICE_STATE_REASON_MODEM_MANAGER_UNAVAILABLE: return Device::StateReason::MODEM_MANAGER_UNAVAILABLE;
		case NM_DEVICE_STATE_REASON_SSID_NOT_FOUND: return Device::StateReason::SSID_NOT_FOUND;
		case NM_DEVICE_STATE_REASON_SECONDARY_CONNECTION_FAILED: return Device::StateReason::SECONDARY_CONNECTION_FAILED;
		case NM_DEVICE_STATE_REASON_DCB_FCOE_FAILED: return Device::StateReason::DCB_FCOE_FAILED;
		case NM_DEVICE_STATE_REASON_TEAMD_CONTROL_FAILED: return Device::StateReason::TEAMD_CONTROL_FAILED;
		case NM_DEVICE_STATE_REASON_MODEM_FAILED: return Device::StateReason::MODEM_FAILED;
		case NM_DEVICE_STATE_REASON_MODEM_AVAILABLE: return Device::StateReason::MODEM_AVAILABLE;
		case NM_DEVICE_STATE_REASON_SIM_PIN_INCORRECT: return Device::StateReason::SIM_PIN_INCORRECT;
		case NM_DEVICE_STATE_REASON_NEW_ACTIVATION: return Device::StateReason::NEW_ACTIVATION;
		case NM_DEVICE_STATE_REASON_PARENT_CHANGED: return Device::StateReason::PARENT_CHANGED;
		case NM_DEVICE_STATE_REASON_PARENT_MANAGED_CHANGED: return Device::StateReason::PARENT_MANAGED_CHANGED;
		case NM_DEVICE_STATE_REASON_OVSDB_FAILED: return Device::StateReason::OVSDB_FAILED;
		// case NM_DEVICE_STATE_REASON_IP_ADDRESS_DUPLICATE: return Device::StateReason::IP_ADDRESS_DUPLICATE;
		// case NM_DEVICE_STATE_REASON_IP_METHOD_UNSUPPORTED: return Device::StateReason::IP_METHOD_UNSUPPORTED;
		default: throw std::runtime_error("libnm::Device::getStateReason() got unexpected reason value "+std::to_string(reason));
	}
}

libnm::ActiveConnection libnm::Device::getActiveConnection()
{
	return nm_device_get_active_connection(pDevice_);
}
