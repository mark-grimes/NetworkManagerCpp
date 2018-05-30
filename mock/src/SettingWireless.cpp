#include "libnm/SettingWireless.h"
#include "libnm/detail/SettingPrivateMembers.h"

libnm::SettingWireless::SettingWireless()
{
}

libnm::SettingWireless::~SettingWireless()
{
}

void libnm::SettingWireless::setMACAddress( const std::string& macAddress )
{
	throw std::logic_error("libnm::SettingWireless::setMACAddress() has not been implemented for the mock classes");
}

void libnm::SettingWireless::setSSID( const std::vector<uint8_t>& ssid )
{
	pData_->ssid_=ssid;
}

void libnm::SettingWireless::setSSID( const std::string& ssid )
{
	pData_->ssid_.clear();
	for( const auto& byte : ssid ) pData_->ssid_.push_back(byte);
}

void libnm::SettingWireless::setMode( libnm::SettingWireless::Mode mode )
{
	pData_->mode_=static_cast<int>(mode);
}
