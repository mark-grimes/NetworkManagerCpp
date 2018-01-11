#ifndef INCLUDEGUARD_libnmtests_ConnectionTests_h
#define INCLUDEGUARD_libnmtests_ConnectionTests_h

// Forward declarations
namespace libnm
{
	class Connection;
}

namespace libnmtests
{
	/** @brief Runs catch.hpp tests on the libnm::Connection
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 11/Jan/2018
	 */
	void test_Connection( const libnm::Connection& connection );
}

#endif
