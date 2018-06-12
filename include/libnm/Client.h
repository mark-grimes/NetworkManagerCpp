#ifndef INCLUDEGUARD_libnm_Client_h
#define INCLUDEGUARD_libnm_Client_h

#include <vector>
#include "libnm/MainLoop.h"
//
// Forward declarations
//
struct _NMClient;
typedef struct _NMClient NMClient;
namespace libnm
{
	class RemoteConnection;
	class Device;
	class Connection;
	class RemoteConnection;
	class ActiveConnection;
	class AccessPoint;
}

namespace libnm
{
	/** @brief Wrapper around the libnm NMClient structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 10/Jan/2018
	 */
	class Client
	{
	public:
		/// Indicate that this is the real hardware class and not the mock object
		static constexpr bool isMock() { return false; }
	public:
		Client();
		Client( const libnm::Client& other );
		Client( libnm::Client&& other );
		libnm::Client& operator=( const libnm::Client& other );
		libnm::Client& operator=( libnm::Client&& other );
		~Client();
		const char* getVersion() const;
		std::vector<libnm::RemoteConnection> getConnections() const;
		std::vector<libnm::Device> getDevices() const;
		libnm::RemoteConnection addConnection( libnm::Connection& connection );
		libnm::ActiveConnection activateConnection( libnm::Connection& connection );
		libnm::ActiveConnection activateConnection( libnm::Connection& connection, libnm::AccessPoint& accessPoint );
	private:
		NMClient* pClient_;
		std::shared_ptr<libnm::MainLoop> pMainLoop_;
	};

} // end of namespace libnm

#endif
