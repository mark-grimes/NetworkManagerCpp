#include "libnm/SettingWireless.h"
#include <NetworkManager.h>

libnm::SettingWireless::SettingWireless()
	: Setting( nullptr )
{
	pSetting_=nm_setting_wireless_new();
}

libnm::SettingWireless::~SettingWireless()
{
}

void libnm::SettingWireless::setSSID( const std::vector<uint8_t>& ssid )
{
	GByteArray *pBytes=g_byte_array_sized_new( ssid.size() );
	g_byte_array_append( pBytes, const_cast<uint8_t*>(ssid.data()), ssid.size() );
	// Note that technically pBytes thinks it owns the memory at ssid.data(),
	// however I call g_byte_array_free with the second parameter as false.

	g_object_set( pSetting_, NM_SETTING_WIRELESS_SSID, pBytes, NULL );

	// Doesn't seem to work if I free the byte array. I presume it takes ownership.
	//g_byte_array_free( pBytes, true );
}

void libnm::SettingWireless::setSSID( const std::string& ssid )
{
	GByteArray *pBytes=g_byte_array_sized_new( ssid.size() );
	g_byte_array_append( pBytes, const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(ssid.data())), ssid.size() );

	g_object_set( pSetting_, NM_SETTING_WIRELESS_SSID, pBytes, NULL );

	// Doesn't seem to work if I free the byte array. I presume it takes ownership.
	//g_byte_array_free( pBytes, true );
}

void libnm::SettingWireless::setMode( libnm::SettingWireless::Mode mode )
{
	switch( mode )
	{
		case Mode::ADHOC :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_MODE, NM_SETTING_WIRELESS_MODE_ADHOC, NULL );
			break;
		case Mode::AP :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_MODE, NM_SETTING_WIRELESS_MODE_AP, NULL );
			break;
		case Mode::INFRA :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_MODE, NM_SETTING_WIRELESS_MODE_INFRA, NULL );
			break;
	}
}
