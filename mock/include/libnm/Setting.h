#ifndef INCLUDEGUARD_libnm_Setting_h
#define INCLUDEGUARD_libnm_Setting_h

#include <memory>
//
// Forward declarations
//
struct _NMSetting;
typedef struct _NMSetting NMSetting;
namespace libnm
{
	class Connection;
}

namespace libnm
{
	// Forward declare the class that holds the mock data
	namespace detail
	{
		struct SettingPrivateMembers;
	}

	/** @brief Mock wrapper around the libnm NMSetting structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 30/May/2018
	 */
	class Setting
	{
		friend class libnm::Connection;
	public:
		virtual ~Setting();

		NMSetting* native_handle();
		const NMSetting* native_handle() const;
	protected:
		Setting();
		void invalidate();
		std::shared_ptr<libnm::detail::SettingPrivateMembers> pData_;
	};

} // end of namespace libnm

#endif
