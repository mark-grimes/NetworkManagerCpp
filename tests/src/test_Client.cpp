#include "libnm/Client.h"
#include "catch.hpp"
#include <nm-version.h>

SCENARIO( "Test that the libnm::Client class performs as expected", "[Client]" )
{
	WHEN( "Test that Client::getVersion() returns something valid" )
	{
		libnm::Client client;
		const char* version=nullptr;
		std::string libnmVersion=std::to_string(NM_MAJOR_VERSION)+"."+std::to_string(NM_MINOR_VERSION)+"."+std::to_string(NM_MICRO_VERSION);
		CHECK_NOTHROW( version=client.getVersion() );
		CHECK( version != nullptr );
	}
} // end of 'SCENARIO ... libnm::Client'
