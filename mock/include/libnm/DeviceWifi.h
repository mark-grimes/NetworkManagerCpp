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
	};

} // end of namespace libnm

#endif
