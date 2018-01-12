#ifndef INCLUDEGUARD_libnm_AccessPoint_h
#define INCLUDEGUARD_libnm_AccessPoint_h

//
// Forward declarations
//
struct _NMAccessPoint;
typedef struct _NMAccessPoint NMAccessPoint;

namespace libnm
{
	/** @brief Wrapper around the libnm NMAccessPoint structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 12/Jan/2018
	 */
	class AccessPoint
	{
	public:
		AccessPoint( NMAccessPoint* pAccessPoint );
		virtual ~AccessPoint();
	protected:
		NMAccessPoint* pAccessPoint_;
	};

} // end of namespace libnm

#endif
