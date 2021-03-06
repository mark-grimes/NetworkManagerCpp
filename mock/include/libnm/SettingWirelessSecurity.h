#ifndef INCLUDEGUARD_libnm_SettingWirelessSecurity_h
#define INCLUDEGUARD_libnm_SettingWirelessSecurity_h

#include "libnm/Setting.h"
#include <string>


namespace libnm
{
	/** @brief Mock class to simulate the wrapper around the libnm NMSettingWirelessSecurity structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 30/May/2018
	 */
	class SettingWirelessSecurity : public libnm::Setting
	{
	public:
		SettingWirelessSecurity();
		virtual ~SettingWirelessSecurity();

		void setPSK( const char* psk );
		void setPSK( const std::string& psk ) { setPSK( psk.c_str() ); }

		enum class KeyMgmt { NONE, IEEE8021X, WPA_NONE, WPA_PSK, WPA_EAP };
		void setKeyMgmt( libnm::SettingWirelessSecurity::KeyMgmt keyMgmt );
	};

} // end of namespace libnm

#endif
