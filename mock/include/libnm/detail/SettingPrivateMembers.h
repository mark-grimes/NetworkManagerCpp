#pragma once

#include <vector>
#include <cstdint>
#include <string>

namespace libnm
{
	namespace detail
	{
		/** @brief Struct to hold settings that can be accessed by subclasses
		 *
		 * @author Mark Grimes (mark.grimes@rymapt.com)
		 * @date 30/May/2018
		 */
		struct SettingPrivateMembers
		{
			// SettingWireless settings
			std::vector<uint8_t> ssid_;
			int mode_;
			// SettingWirelessSecurity settings
			std::string psk_;
			int keyMgmt_;
		};
	} // end of namespace detail
} // end of namespace libnm
