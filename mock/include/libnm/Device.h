#ifndef INCLUDEGUARD_libnm_Device_h
#define INCLUDEGUARD_libnm_Device_h

#include <string>
//
// Forward declarations
//
namespace libnm
{
	class Client;
	class DeviceWifi;
}

namespace libnm
{
	/** @brief Mock implementation of the wrapper around the libnm NMDevice structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 20/May/2018
	 */
	class Device
	{
		friend class libnm::Client;
	public:
		enum class DeviceType { UNKNOWN, MACSEC, OLPC, BRIDGE, ADSL, INFINIBAND, MACVLAN, TEAM, VXLAN, MODEM, VLAN, BT, IP, BOND, ETHERNET, TUN, GENERIC, WIFI };
		Device( const libnm::Device& other ) = default;
		Device( libnm::Device&& other ) = default;
		libnm::Device& operator=( const libnm::Device& other ) = default;
		libnm::Device& operator=( libnm::Device&& other ) = default;
		virtual ~Device();

		libnm::Device::DeviceType type() const;
		libnm::DeviceWifi asDeviceWifi();

		const char* getIface() const;
		const char* getDriver() const;
	protected:
		template<typename string_1,typename string_2>
		Device( libnm::Device::DeviceType type, string_1&& interface, string_2&& driver )
			: type_(type), interface_(std::forward<string_1>(interface)), driver_(std::forward<string_2>(driver))
		{ /* No operation */ }
		libnm::Device::DeviceType type_;
		const std::string interface_;
		const std::string driver_;
	};

} // end of namespace libnm

#endif
