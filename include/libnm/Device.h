#ifndef INCLUDEGUARD_libnm_Device_h
#define INCLUDEGUARD_libnm_Device_h

//
// Forward declarations
//
struct _NMDevice;
typedef struct _NMDevice NMDevice;
namespace libnm
{
	class Client;
	class DeviceWifi;
}

namespace libnm
{
	/** @brief Wrapper around the libnm NMDevice structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 11/Jan/2018
	 */
	class Device
	{
		friend class libnm::Client;
	public:
		enum class DeviceType { UNKNOWN, MACSEC, OLPC, BRIDGE, ADSL, INFINIBAND, MACVLAN, TEAM, VXLAN, MODEM, VLAN, BT, WIMAX, IP, BOND, ETHERNET, TUN, GENERIC, WIFI };
		virtual ~Device();

		libnm::Device::DeviceType type() const;
		libnm::DeviceWifi asDeviceWifi();

		const char* getIface() const;
		const char* getDriver() const;
	protected:
		Device( NMDevice* pDevice );
		NMDevice* pDevice_;
	};

} // end of namespace libnm

#endif
