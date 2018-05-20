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

		std::vector<libnm::AccessPoint> getAccessPoints() const;
	public:
		template<typename string_1,typename string_2>
		DeviceWifi( libnm::Device::DeviceType type, string_1&& interface, string_2&& driver )
			: libnm::Device(type,std::forward<string_1>(interface),std::forward<string_2>(driver))
		{ /* No operation */ }
	};

} // end of namespace libnm

#endif
