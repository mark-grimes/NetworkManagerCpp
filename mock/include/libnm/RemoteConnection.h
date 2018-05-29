#ifndef INCLUDEGUARD_libnm_RemoteConnection_h
#define INCLUDEGUARD_libnm_RemoteConnection_h

#include "libnm/Connection.h"
//
// Forward declarations
//
namespace libnm
{
	class Client;
}


namespace libnm
{
	/** @brief Mock implementation of the wrapper around the libnm NMRemoteConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 20/May/2018
	 */
	class RemoteConnection : public libnm::Connection
	{
		friend class libnm::Client;
	public:
		virtual ~RemoteConnection();
		bool save() const;
		bool deleteConnection();
	protected:
		template<typename string_1,typename string_2>
		RemoteConnection( string_1&& uuid, string_2&& id )
			: Connection( std::forward<string_1>(uuid), std::forward<string_2>(id) )
		{ /* No operation */ }
	};

} // end of namespace libnm

#endif
