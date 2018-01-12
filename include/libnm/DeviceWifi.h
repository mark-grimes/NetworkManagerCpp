#ifndef INCLUDEGUARD_libnm_DeviceWifi_h
#define INCLUDEGUARD_libnm_DeviceWifi_h

#include "libnm/Device.h"
//
// Forward declarations
//
struct _NMDeviceWifi;
typedef struct _NMDeviceWifi NMDeviceWifi;

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
	};

} // end of namespace libnm

#endif
