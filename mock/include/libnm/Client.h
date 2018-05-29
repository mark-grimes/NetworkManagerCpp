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
	public:
		// Extra methods to set up mocking behaviour
		template<typename uuid_string,typename id_string>
		void mock_addConnection( uuid_string&& uuid, id_string&& id )
		{
			connections_.push_back( libnm::RemoteConnection(std::forward<uuid_string>(uuid),std::forward<id_string>(id)) );
		}
	protected:
		std::vector<libnm::RemoteConnection> connections_;
	};

} // end of namespace libnm

#endif
