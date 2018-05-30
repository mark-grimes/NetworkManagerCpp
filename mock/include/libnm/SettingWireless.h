#ifndef INCLUDEGUARD_libnm_SettingWireless_h
#define INCLUDEGUARD_libnm_SettingWireless_h

#include "libnm/Setting.h"
#include <vector>
#include <string>

namespace libnm
{
	/** @brief Mock wrapper around the libnm NMSettingWireless structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 30/May/2018
	 */
	class SettingWireless : public libnm::Setting
	{
	public:
		SettingWireless();
		virtual ~SettingWireless();

		void setMACAddress( const std::string& ssid );

		void setSSID( const std::vector<uint8_t>& ssid );
		void setSSID( const std::string& ssid );

		enum class Mode { ADHOC, AP, INFRA };
		void setMode( libnm::SettingWireless::Mode mode );
	};

} // end of namespace libnm

#endif
