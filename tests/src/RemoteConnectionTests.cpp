#include "libnmtests/RemoteConnectionTests.h"
#include "libnmtests/ConnectionTests.h"
#include "libnm/RemoteConnection.h"
#include "catch.hpp"

void libnmtests::test_RemoteConnection( const libnm::RemoteConnection& connection )
{
	// Perform standard tests on the libnm::Connection super class first
	libnmtests::test_Connection( connection );
} // end of function libnmtests::test_RemoteConnection
