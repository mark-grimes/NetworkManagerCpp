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
}

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
	private:
	};

} // end of namespace libnm

#endif
