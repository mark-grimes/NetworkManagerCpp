#include "libnm/Client.h"
#include "catch.hpp"

SCENARIO( "Test that the libnm::Client class performs as expected", "[Client]" )
{
	WHEN( "Test that Client::getVersion() returns something valid" )
	{
		libnm::Client client;
		const char* version=nullptr;
		CHECK_NOTHROW( version=client.getVersion() );
		CHECK( version != nullptr );
	}
} // end of 'SCENARIO ... libnm::Client'
