#include "libnm/Device.h"
#include <stdexcept>
#include <iostream>
#include "libnm/DeviceWifi.h"
#include "libnm/ActiveConnection.h"
#include "libnm/detail/DevicePrivateMembers.h"


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

libnm::Device::Device( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver )
	: pData_( std::make_shared<libnm::detail::DevicePrivateMembers>() )
{
	pData_->type_=type;
	pData_->interface_=interface;
	pData_->driver_=driver;
	pData_->ipAddress_="169.254.0.23"; // Arbitrary rubbish
}

libnm::Device::Device( std::shared_ptr<libnm::detail::DevicePrivateMembers> pData ) : pData_(pData)
{
}

libnm::Device::~Device()
{
}

libnm::Device::DeviceType libnm::Device::type() const
{
	return pData_->type_;
}

libnm::DeviceWifi libnm::Device::asDeviceWifi()
{
	if( pData_->type_!=DeviceType::WIFI ) throw std::runtime_error("Device::asDeviceWifi called on a non-WIFI device");
	return libnm::DeviceWifi( pData_ );
}

const char* libnm::Device::getIface() const
{
	return pData_->interface_.c_str();
}

const char* libnm::Device::getDriver() const
{
	return pData_->driver_.c_str();
}

const char* libnm::Device::getIPIface() const
{
	return pData_->ipAddress_.c_str();
}

libnm::Device::State libnm::Device::getState() const
{
	throw std::logic_error("libnm::Device::getState() has not been implemented for the mock classes");
}

libnm::Device::StateReason libnm::Device::getStateReason() const
{
	throw std::logic_error("libnm::Device::getStateReason() has not been implemented for the mock classes");
}

libnm::ActiveConnection libnm::Device::getActiveConnection()
{
	throw std::logic_error("libnm::Device::getActiveConnection() has not been implemented for the mock classes");
}

void libnm::Device::mock_setIPIface( const std::string& address )
{
	pData_->ipAddress_=address;
}
