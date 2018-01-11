#ifndef INCLUDEGUARD_libnm_Device_h
#define INCLUDEGUARD_libnm_Device_h

//
// Forward declarations
//
struct _NMDevice;
typedef struct _NMDevice NMDevice;
namespace libnm
{
	class Client;
}

namespace libnm
{
	/** @brief Wrapper around the libnm NMDevice structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 11/Jan/2018
	 */
	class Device
 	{
		friend class libnm::Client;
 	public:
 		~Device();
		const char* getIface() const;
		const char* getDriver() const;
 	protected:
 		Device( NMDevice* pDevice );
 		NMDevice* pDevice_;
 	};

} // end of namespace libnm

#endif
