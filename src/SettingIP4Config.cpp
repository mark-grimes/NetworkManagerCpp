#include "libnm/SettingIP4Config.h"
#include <NetworkManager.h>

libnm::SettingIP4Config::SettingIP4Config()
	: SettingIPConfig( nullptr )
{
	pSetting_=nm_setting_ip4_config_new();
}

libnm::SettingIP4Config::~SettingIP4Config()
{
}

void libnm::SettingIP4Config::setMethod( libnm::SettingIP4Config::Method method )
{
	switch( method )
	{
		case Method::AUTO :
			g_object_set( pSetting_, NM_SETTING_IP_CONFIG_METHOD, NM_SETTING_IP4_CONFIG_METHOD_AUTO, NULL );
			break;
		case Method::LINK_LOCAL :
			g_object_set( pSetting_, NM_SETTING_IP_CONFIG_METHOD, NM_SETTING_IP4_CONFIG_METHOD_LINK_LOCAL, NULL );
			break;
		case Method::MANUAL :
			g_object_set( pSetting_, NM_SETTING_IP_CONFIG_METHOD, NM_SETTING_IP4_CONFIG_METHOD_MANUAL, NULL );
			break;
		case Method::SHARED :
			g_object_set( pSetting_, NM_SETTING_IP_CONFIG_METHOD, NM_SETTING_IP4_CONFIG_METHOD_SHARED, NULL );
			break;
		case Method::DISABLED :
			g_object_set( pSetting_, NM_SETTING_IP_CONFIG_METHOD, NM_SETTING_IP4_CONFIG_METHOD_DISABLED, NULL );
			break;
	}
}

int libnm::SettingIP4Config::family() const
{
	return AF_INET;
}
