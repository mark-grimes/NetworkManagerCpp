#include "libnm/SettingWirelessSecurity.h"
#include <NetworkManager.h>

libnm::SettingWirelessSecurity::SettingWirelessSecurity()
	: Setting( nullptr )
{
	pSetting_=nm_setting_wireless_security_new();
}

libnm::SettingWirelessSecurity::~SettingWirelessSecurity()
{
}

void libnm::SettingWirelessSecurity::setPSK( const char* psk )
{
	g_object_set( pSetting_, NM_SETTING_WIRELESS_SECURITY_PSK, psk, NULL );
}

void libnm::SettingWirelessSecurity::setKeyMgmt( libnm::SettingWirelessSecurity::KeyMgmt keyMgmt )
{
	switch( keyMgmt )
	{
		case KeyMgmt::NONE :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_SECURITY_KEY_MGMT, "none", NULL );
			break;
		case KeyMgmt::IEEE8021X :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_SECURITY_KEY_MGMT, "ieee8021x", NULL );
			break;
		case KeyMgmt::WPA_NONE :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_SECURITY_KEY_MGMT, "wpa-none", NULL );
			break;
		case KeyMgmt::WPA_PSK :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_SECURITY_KEY_MGMT, "wpa-psk", NULL );
			break;
		case KeyMgmt::WPA_EAP :
			g_object_set( pSetting_, NM_SETTING_WIRELESS_SECURITY_KEY_MGMT, "wpa-eap", NULL );
			break;
	}
}
