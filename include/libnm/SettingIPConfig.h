#ifndef INCLUDEGUARD_libnm_SettingIPConfig_h
#define INCLUDEGUARD_libnm_SettingIPConfig_h

#include "libnm/Setting.h"
#include <string>
//
// Forward declarations
//
struct _NMSettingIPConfig;
typedef struct _NMSettingIPConfig NMSettingIPConfig;


namespace libnm
{
	/** @brief Wrapper around the libnm NMSettingIPConfig structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 21/Jan/2018
	 */
	class SettingIPConfig : public libnm::Setting
	{
	public:
		SettingIPConfig();
		virtual ~SettingIPConfig();

		void addAddress( const char* address, int prefix );
		void addAddress( const std::string& address, int prefix ) { addAddress( address.c_str(), prefix ); }
	protected:
		SettingIPConfig( NMSettingIPConfig* pSettingIPConfig );

		/** @brief Either AF_INET or AF_INET6 depending on whether this is a concrete SettingIP4Config or SettingIP6Config */
		virtual int family() const = 0;
	};

} // end of namespace libnm

#endif
