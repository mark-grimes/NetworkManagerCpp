#include "libnm/SettingWirelessSecurity.h"
#include "libnm/detail/SettingPrivateMembers.h"

libnm::SettingWirelessSecurity::SettingWirelessSecurity()
{
}

libnm::SettingWirelessSecurity::~SettingWirelessSecurity()
{
}

void libnm::SettingWirelessSecurity::setPSK( const char* psk )
{
	pData_->psk_=psk;
}

void libnm::SettingWirelessSecurity::setKeyMgmt( libnm::SettingWirelessSecurity::KeyMgmt keyMgmt )
{
	pData_->keyMgmt_=static_cast<int>(keyMgmt);
}
