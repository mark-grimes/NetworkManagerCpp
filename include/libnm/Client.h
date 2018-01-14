#ifndef INCLUDEGUARD_libnm_Client_h
#define INCLUDEGUARD_libnm_Client_h

#include <vector>
//
// Forward declarations
//
struct _NMClient;
typedef struct _NMClient NMClient;
namespace libnm
{
	class RemoteConnection;
	class Device;
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
		Client();
		Client( const libnm::Client& other );
		Client( libnm::Client&& other );
		libnm::Client& operator=( const libnm::Client& other );
		libnm::Client& operator=( libnm::Client&& other );
		~Client();
		const char* getVersion() const;
		std::vector<libnm::RemoteConnection> getConnections() const;
		std::vector<libnm::Device> getDevices() const;
	private:
		NMClient* pClient_;
	};

} // end of namespace libnm

#endif
