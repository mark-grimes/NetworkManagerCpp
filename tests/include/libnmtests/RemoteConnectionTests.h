#ifndef INCLUDEGUARD_libnmtests_RemoteConnectionTests_h
#define INCLUDEGUARD_libnmtests_RemoteConnectionTests_h

// Forward declarations
namespace libnm
{
	class RemoteConnection;
}

namespace libnmtests
{
	/** @brief Runs catch.hpp tests on the libnm::RemoteConnection
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 11/Jan/2018
	 */
	void test_RemoteConnection( const libnm::RemoteConnection& connection );
}

#endif
