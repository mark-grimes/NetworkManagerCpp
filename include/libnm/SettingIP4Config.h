#ifndef INCLUDEGUARD_libnm_SettingIP4Config_h
#define INCLUDEGUARD_libnm_SettingIP4Config_h

#include "libnm/SettingIPConfig.h"
//
// Forward declarations
//
struct _NMSettingIP4Config;
typedef struct _NMSettingIP4Config NMSettingIP4Config;


namespace libnm
{
	/** @brief Wrapper around the libnm NMSettingIP4Config structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 21/Jan/2018
	 */
	class SettingIP4Config : public libnm::SettingIPConfig
	{
	public:
		SettingIP4Config();
		virtual ~SettingIP4Config();

		enum class Method { AUTO, LINK_LOCAL, MANUAL, SHARED, DISABLED };
		virtual void setMethod( libnm::SettingIP4Config::Method method );
	protected:
		virtual int family() const;
	};

} // end of namespace libnm

#endif
