#ifndef INCLUDEGUARD_libnm_Setting_h
#define INCLUDEGUARD_libnm_Setting_h

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
	/** @brief Wrapper around the libnm NMSetting structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 14/Jan/2018
	 */
	class Setting
	{
		friend class libnm::Connection;
	public:
		Setting( const libnm::Setting& other );
		Setting( libnm::Setting&& other );
		libnm::Setting& operator=( const libnm::Setting& other );
		libnm::Setting& operator=( libnm::Setting&& other );
		virtual ~Setting();

		NMSetting* native_handle();
		const NMSetting* native_handle() const;
	protected:
		Setting( NMSetting* pSetting );
		void invalidate();
		NMSetting* pSetting_;
	};

} // end of namespace libnm

#endif
