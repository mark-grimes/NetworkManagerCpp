#include "libnm/SettingIP6Config.h"
#include <NetworkManager.h>

libnm::SettingIP6Config::SettingIP6Config()
	: SettingIPConfig( nullptr )
{
	pSetting_=nm_setting_ip6_config_new();
}

libnm::SettingIP6Config::~SettingIP6Config()
{
}

int libnm::SettingIP6Config::family() const
{
	return AF_INET6;
}
