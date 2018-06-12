#ifndef INCLUDEGUARD_libnm_ActiveConnection_h
#define INCLUDEGUARD_libnm_ActiveConnection_h

//
// Forward declarations
//
struct _NMActiveConnection;
typedef struct _NMActiveConnection NMActiveConnection;

namespace libnm
{
	/** @brief Mock object to simulate wrapper around NMActiveConnection
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 29/May/2018
	 */
	class ActiveConnection
	{
	public:
		enum class State { UNKNOWN, ACTIVATING, ACTIVATED, DEACTIVATING, DEACTIVATED };
		enum class StateReason { UNKNOWN, NONE, USER_DISCONNECTED, DEVICE_DISCONNECTED, SERVICE_STOPPED, IP_CONFIG_INVALID, CONNECT_TIMEOUT, SERVICE_START_TIMEOUT, SERVICE_START_FAILED, NO_SECRETS, LOGIN_FAILED, CONNECTION_REMOVED, DEPENDENCY_FAILED, DEVICE_REALIZE_FAILED, DEVICE_REMOVED };

		NMActiveConnection* native_handle();
		const NMActiveConnection* native_handle() const;

		const char* getUuid() const;
		const char* getId() const;
		ActiveConnection::State getState() const;
		ActiveConnection::StateReason getStateReason() const;
	};

} // end of namespace libnm


#include <iosfwd>
std::ostream& operator<<( std::ostream& stream, libnm::ActiveConnection::State state );
std::ostream& operator<<( std::ostream& stream, libnm::ActiveConnection::StateReason reason );

#endif
