#include "libnm/DeviceWifi.h"
#include "libnm/AccessPoint.h"
#include "libnm/detail/DevicePrivateMembers.h"

libnm::DeviceWifi::~DeviceWifi()
{
}

libnm::AccessPoint libnm::DeviceWifi::getActiveAccessPoint()
{
	// For now just return the first one
	if( pData_->accessPoints_.empty() ) throw std::runtime_error("libnm::DeviceWifi::getActiveAccessPoint() - no active access point");
	return pData_->accessPoints_.front();
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
