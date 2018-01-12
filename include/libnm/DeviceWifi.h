#ifndef INCLUDEGUARD_libnm_DeviceWifi_h
#define INCLUDEGUARD_libnm_DeviceWifi_h

#include "libnm/Device.h"
#include <vector>
//
// Forward declarations
//
struct _NMDeviceWifi;
typedef struct _NMDeviceWifi NMDeviceWifi;
namespace libnm
{
	class AccessPoint;
}

namespace libnm
{
	/** @brief Wrapper around the libnm NMDeviceWifi structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 12/Jan/2018
	 */
	class DeviceWifi : public libnm::Device
	{
	public:
		DeviceWifi( NMDeviceWifi* pDeviceWifi );
		virtual ~DeviceWifi();

		std::vector<libnm::AccessPoint> getAccessPoints() const;
	};

} // end of namespace libnm

#endif
