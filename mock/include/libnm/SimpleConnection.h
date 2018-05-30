#ifndef INCLUDEGUARD_libnm_SimpleConnection_h
#define INCLUDEGUARD_libnm_SimpleConnection_h

#include <string>
#include "libnm/Connection.h"

namespace libnm
{
	/** @brief Mock to simulate the wrapper around the libnm NMSimpleConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 30/May/2018
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
