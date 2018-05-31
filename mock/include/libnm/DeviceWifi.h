#ifndef INCLUDEGUARD_libnm_DeviceWifi_h
#define INCLUDEGUARD_libnm_DeviceWifi_h

#include "libnm/Device.h"
#include <vector>
//
// Forward declarations
//
namespace libnm
{
	class AccessPoint;
}

namespace libnm
{
	/** @brief Mock implementation of the wrapper around the libnm NMDeviceWifi structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 20/May/2018
	 */
	class DeviceWifi : public libnm::Device
	{
	public:
		virtual ~DeviceWifi();

		libnm::AccessPoint getActiveAccessPoint();
		std::vector<libnm::AccessPoint> getAccessPoints() const;
	public:
		// Extra methods to set up mocking behaviour
		DeviceWifi( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver );
		void mock_addAccessPoint( const std::vector<uint8_t>& ssid, const std::string& bssid, uint32_t maxBitrate, uint8_t strength );
	protected:
		friend class libnm::Device;
		explicit DeviceWifi( std::shared_ptr<libnm::detail::DevicePrivateMembers> pData );
	};

} // end of namespace libnm

#endif
