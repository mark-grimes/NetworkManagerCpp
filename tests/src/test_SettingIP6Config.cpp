#include "libnm/SettingIP6Config.h"
#include <memory>
#include "catch.hpp"

SCENARIO( "Test that the libnm::SettingIP6Config class performs as expected", "[SettingIP6Config]" )
{
	WHEN( "Test that IP6 addresses are parsed properly" )
	{
		// Need to use pointer so that I can wrap constructor in CHECK_NOTHROW block
		std::unique_ptr<libnm::SettingIP6Config> pSetting;
		REQUIRE_NOTHROW( pSetting.reset(new libnm::SettingIP6Config) );
		REQUIRE( pSetting != nullptr );

		// Check IPv4 addresses are not considered valid for IPv6
		CHECK_THROWS( pSetting->addAddress( "192.168.0.1", 24 ) );
		// Check gibberish is not valid
		CHECK_THROWS( pSetting->addAddress( "fish", 24 ) );

		CHECK_NOTHROW( pSetting->addAddress( "2001:0db8:ac10:fe01:0000:0000:0000:0000", 24 ) );
		CHECK_NOTHROW( pSetting->addAddress( "2001:0DB8:AC10:FE01:0000:0000:0000:0000", 24 ) );
		CHECK_NOTHROW( pSetting->addAddress( "2001:0db8:ac10:fe01::", 24 ) );
		CHECK_NOTHROW( pSetting->addAddress( "2001:0DB8:AC10:FE01::", 24 ) );
	}
} // end of 'SCENARIO ... libnm::SettingIP6Config'
