#include "libnm/SettingIP4Config.h"
#include <memory>
#include "catch.hpp"

SCENARIO( "Test that the libnm::SettingIP4Config class performs as expected", "[SettingIP4Config]" )
{
	WHEN( "Test that IP4 addresses are parsed properly" )
	{
		// Need to use pointer so that I can wrap constructor in CHECK_NOTHROW block
		std::unique_ptr<libnm::SettingIP4Config> pSetting;
		REQUIRE_NOTHROW( pSetting.reset(new libnm::SettingIP4Config) );
		REQUIRE( pSetting != nullptr );

		// Check gibberish is not valid
		CHECK_THROWS( pSetting->addAddress( "fish", 24 ) );
		// Check that IPv6 addresses are not valid as IPv4 addresses
		CHECK_THROWS( pSetting->addAddress( "2001:0db8:ac10:fe01:0000:0000:0000:0000", 24 ) );
		CHECK_THROWS( pSetting->addAddress( "2001:0DB8:AC10:FE01:0000:0000:0000:0000", 24 ) );
		CHECK_THROWS( pSetting->addAddress( "2001:0db8:ac10:fe01::", 24 ) );
		CHECK_THROWS( pSetting->addAddress( "2001:0DB8:AC10:FE01::", 24 ) );

		CHECK_NOTHROW( pSetting->addAddress( "192.168.0.1", 24 ) );
	}
} // end of 'SCENARIO ... libnm::SettingIP4Config'
