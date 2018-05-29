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
	// Forward declare the pimple class
	namespace detail
	{
		struct DevicePrivateMembers;
	}

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
		Device( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver );
		explicit Device( std::shared_ptr<libnm::detail::DevicePrivateMembers> pData );
		std::shared_ptr<libnm::detail::DevicePrivateMembers> pData_;
	};

} // end of namespace libnm

#endif
