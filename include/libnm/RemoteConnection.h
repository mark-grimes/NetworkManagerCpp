#ifndef INCLUDEGUARD_libnm_RemoteConnection_h
#define INCLUDEGUARD_libnm_RemoteConnection_h

#include "libnm/Connection.h"
//
// Forward declarations
//
struct _NMRemoteConnection;
typedef struct _NMRemoteConnection NMRemoteConnection;
namespace libnm
{
	class Client;
}


namespace libnm
{
	/** @brief Wrapper around the libnm NMRemoteConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 10/Jan/2018
	 */
	 class RemoteConnection : public libnm::Connection
 	{
 		friend class libnm::Client;
 	public:
 		~RemoteConnection();
 	protected:
 		RemoteConnection( NMRemoteConnection* pRemoteConnection );
 	};

} // end of namespace libnm

#endif
