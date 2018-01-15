#ifndef INCLUDEGUARD_libnm_SettingWireless_h
#define INCLUDEGUARD_libnm_SettingWireless_h

#include "libnm/Setting.h"
#include <vector>
#include <string>
//
// Forward declarations
//
struct _NMSettingWireless;
typedef struct _NMSettingWireless NMSettingWireless;


namespace libnm
{
	/** @brief Wrapper around the libnm NMSettingWireless structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 14/Jan/2018
	 */
	class SettingWireless : public libnm::Setting
	{
	public:
		SettingWireless();
		virtual ~SettingWireless();

		void setSSID( const std::vector<uint8_t>& ssid );
		void setSSID( const std::string& ssid );

		enum class Mode { ADHOC, AP, INFRA };
		void setMode( libnm::SettingWireless::Mode mode );
	};

} // end of namespace libnm

#endif
