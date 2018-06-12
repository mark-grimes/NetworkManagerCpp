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
	class ActiveConnection;
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
		enum class DeviceType { UNKNOWN, MACSEC, OLPC, BRIDGE, ADSL, INFINIBAND, MACVLAN, TEAM, VXLAN, MODEM, VLAN, BT, IP, BOND, ETHERNET, TUN, GENERIC, WIFI };
		enum class State{ UNKNOWN, UNMANAGED, UNAVAILABLE, DISCONNECTED, PREPARE, CONFIG, NEED_AUTH, IP_CONFIG, IP_CHECK, SECONDARIES, ACTIVATED, DEACTIVATING, FAILED };
		enum class StateReason{ NONE, UNKNOWN, NOW_MANAGED, NOW_UNMANAGED, CONFIG_FAILED, IP_CONFIG_UNAVAILABLE, IP_CONFIG_EXPIRED, NO_SECRETS, SUPPLICANT_DISCONNECT, SUPPLICANT_CONFIG_FAILED, SUPPLICANT_FAILED, SUPPLICANT_TIMEOUT, PPP_START_FAILED, PPP_DISCONNECT, PPP_FAILED, DHCP_START_FAILED, DHCP_ERROR, DHCP_FAILED, SHARED_START_FAILED, SHARED_FAILED, AUTOIP_START_FAILED, AUTOIP_ERROR, AUTOIP_FAILED, MODEM_BUSY, MODEM_NO_DIAL_TONE, MODEM_NO_CARRIER, MODEM_DIAL_TIMEOUT, MODEM_DIAL_FAILED, MODEM_INIT_FAILED, GSM_APN_FAILED, GSM_REGISTRATION_NOT_SEARCHING, GSM_REGISTRATION_DENIED, GSM_REGISTRATION_TIMEOUT, GSM_REGISTRATION_FAILED, GSM_PIN_CHECK_FAILED, FIRMWARE_MISSING, REMOVED, SLEEPING, CONNECTION_REMOVED, USER_REQUESTED, CARRIER, CONNECTION_ASSUMED, SUPPLICANT_AVAILABLE, MODEM_NOT_FOUND, BT_FAILED, GSM_SIM_NOT_INSERTED, GSM_SIM_PIN_REQUIRED, GSM_SIM_PUK_REQUIRED, GSM_SIM_WRONG, INFINIBAND_MODE, DEPENDENCY_FAILED, BR2684_FAILED, MODEM_MANAGER_UNAVAILABLE, SSID_NOT_FOUND, SECONDARY_CONNECTION_FAILED, DCB_FCOE_FAILED, TEAMD_CONTROL_FAILED, MODEM_FAILED, MODEM_AVAILABLE, SIM_PIN_INCORRECT, NEW_ACTIVATION, PARENT_CHANGED, PARENT_MANAGED_CHANGED, OVSDB_FAILED, IP_ADDRESS_DUPLICATE, IP_METHOD_UNSUPPORTED };
		Device( const libnm::Device& other );
		Device( libnm::Device&& other );
		libnm::Device& operator=( const libnm::Device& other );
		libnm::Device& operator=( libnm::Device&& other );
		virtual ~Device();

		libnm::Device::DeviceType type() const;
		libnm::DeviceWifi asDeviceWifi();

		const char* getIface() const;
		const char* getDriver() const;
		const char* getIPIface() const;
		Device::State getState() const;
		Device::StateReason getStateReason() const;
		libnm::ActiveConnection getActiveConnection();
	protected:
		Device( NMDevice* pDevice );
		NMDevice* pDevice_;
	};

} // end of namespace libnm

#include <iosfwd>
std::ostream& operator<<( std::ostream& stream, libnm::Device::State state );
std::ostream& operator<<( std::ostream& stream, libnm::Device::StateReason reason );

#endif
