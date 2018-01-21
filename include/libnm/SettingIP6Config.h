#ifndef INCLUDEGUARD_libnm_SettingIP6Config_h
#define INCLUDEGUARD_libnm_SettingIP6Config_h

#include "libnm/SettingIPConfig.h"
//
// Forward declarations
//
struct _NMSettingIP6Config;
typedef struct _NMSettingIP6Config NMSettingIP6Config;


namespace libnm
{
	/** @brief Wrapper around the libnm NMSettingIP6Config structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 21/Jan/2018
	 */
	class SettingIP6Config : public libnm::SettingIPConfig
	{
	public:
		SettingIP6Config();
		virtual ~SettingIP6Config();
	protected:
		virtual int family() const;
	};

} // end of namespace libnm

#endif
