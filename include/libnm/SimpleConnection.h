#ifndef INCLUDEGUARD_libnm_SimpleConnection_h
#define INCLUDEGUARD_libnm_SimpleConnection_h

#include <string>
#include "libnm/Connection.h"
//
// Forward declarations
//
struct _NMSimpleConnection;
typedef struct _NMSimpleConnection NMSimpleConnection;


namespace libnm
{
	/** @brief Wrapper around the libnm NMSimpleConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 14/Jan/2018
	 */
	class SimpleConnection : public libnm::Connection
	{
	public:
		enum class ConnectionType { WIRED, WIRELESS };
		SimpleConnection( const std::string& name, ConnectionType type );
		virtual ~SimpleConnection();
	};

} // end of namespace libnm

#endif
