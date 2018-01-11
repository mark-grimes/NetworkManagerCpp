#include "libnm/Client.h"
#include <memory>
#include "catch.hpp"

SCENARIO( "Test that the libnm::Client class performs as expected", "[Client]" )
{
	WHEN( "Test that Client::getVersion() returns something valid" )
	{
		// Need to use pointer so that I can wrap constructor in CHECK_NOTHROW block
		std::unique_ptr<libnm::Client> pClient;
		const char* version=nullptr;
		REQUIRE_NOTHROW( pClient.reset(new libnm::Client) );
		REQUIRE( pClient != nullptr );
		CHECK_NOTHROW( version=pClient->getVersion() );
		CHECK( version != nullptr );
		// TODO check the version string is sensible
	}
} // end of 'SCENARIO ... libnm::Client'
