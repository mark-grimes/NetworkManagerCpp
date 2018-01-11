#include "libnmtests/ConnectionTests.h"
#include "libnm/Connection.h"
#include "catch.hpp"

void libnmtests::test_Connection( const libnm::Connection& connection )
{
	CHECK( connection.getId() != nullptr );
} // end of function libnmtests::test_Connection
