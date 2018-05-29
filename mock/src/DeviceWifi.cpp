#include "libnm/DeviceWifi.h"
#include "libnm/AccessPoint.h"
#include "libnm/detail/DevicePrivateMembers.h"

libnm::DeviceWifi::~DeviceWifi()
{
}

std::vector<libnm::AccessPoint> libnm::DeviceWifi::getAccessPoints() const
{
	return pData_->accessPoints_;
}

libnm::DeviceWifi::DeviceWifi( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver )
	: libnm::Device(type,interface,driver)
{
	/* No operation */
}

void libnm::DeviceWifi::mock_addAccessPoint( const std::vector<uint8_t>& ssid, const std::string& bssid, uint32_t maxBitrate, uint8_t strength )
{
	pData_->accessPoints_.emplace_back( ssid, bssid, maxBitrate, strength );
}

libnm::DeviceWifi::DeviceWifi( std::shared_ptr<libnm::detail::DevicePrivateMembers> pData ) : Device(pData)
{
}
