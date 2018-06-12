#ifndef INCLUDEGUARD_libnm_ActiveConnection_h
#define INCLUDEGUARD_libnm_ActiveConnection_h

//
// Forward declarations
//
struct _NMActiveConnection;
typedef struct _NMActiveConnection NMActiveConnection;

namespace libnm
{
	/** @brief Mock object to simulate wrapper around NMActiveConnection
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 29/May/2018
	 */
	class ActiveConnection
	{
	public:
		NMActiveConnection* native_handle();
		const NMActiveConnection* native_handle() const;

		const char* getUuid() const;
		const char* getId() const;
	};

} // end of namespace libnm

#endif
