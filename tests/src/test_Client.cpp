#include "libnm/Client.h"
#include "libnm/RemoteConnection.h"
#include "libnmtests/RemoteConnectionTests.h"
#include "libnm/Device.h"
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
	WHEN( "Test Client::getConnections() method" )
	{
		libnm::Client client;
		std::vector<libnm::RemoteConnection> connections;
		REQUIRE_NOTHROW( connections=client.getConnections() );
		CHECK( connections.size() > 0 );
		for( const auto& connection : connections )
		{
			libnmtests::test_RemoteConnection( connection );
		}
	}
	WHEN( "Test Client::getDevices() method" )
	{
		libnm::Client client;
		std::vector<libnm::Device> devices;
		REQUIRE_NOTHROW( devices=client.getDevices() );
		CHECK( devices.size() > 0 );
	}
} // end of 'SCENARIO ... libnm::Client'
