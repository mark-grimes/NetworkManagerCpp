#ifndef INCLUDEGUARD_libnm_Client_h
#define INCLUDEGUARD_libnm_Client_h

#include <vector>
//
// Forward declarations
//
namespace libnm
{
	class RemoteConnection;
	class Device;
	class Connection;
	class RemoteConnection;
	class ActiveConnection;
}
#include "libnm/Device.h" // Only required for the mock class because I refer to libnm::Device::DeviceType

namespace libnm
{
	/** @brief Mock version of the wrapper around the libnm NMClient structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 20/May/2018
	 */
	class Client
	{
	public:
		/// Indicate that this is not running on real hardware
		static constexpr bool isMock() { return true; }
	public:
		Client();
		Client( const libnm::Client& other ) = default;
		Client( libnm::Client&& other ) = default;
		libnm::Client& operator=( const libnm::Client& other ) = default;
		libnm::Client& operator=( libnm::Client&& other ) = default;
		~Client();
		const char* getVersion() const;
		std::vector<libnm::RemoteConnection> getConnections() const;
		std::vector<libnm::Device> getDevices() const;
		libnm::RemoteConnection addConnection( libnm::Connection& connection );
		libnm::ActiveConnection activateConnection( libnm::Connection& connection );
	public:
		// Extra methods to set up mocking behaviour
		void mock_addDevice( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver );
		libnm::Device& mock_getDevice( size_t index );
		void mock_addConnection( const std::string& uuid, const std::string& id );
	protected:
		std::vector<libnm::Device> devices_;
		std::vector<libnm::RemoteConnection> connections_;
	};

} // end of namespace libnm

#endif
