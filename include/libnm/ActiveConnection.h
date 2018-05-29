#ifndef INCLUDEGUARD_libnm_ActiveConnection_h
#define INCLUDEGUARD_libnm_ActiveConnection_h

//
// Forward declarations
//
struct _NMActiveConnection;
typedef struct _NMActiveConnection NMActiveConnection;
namespace libnm
{
	class Client;
}

namespace libnm
{
	/** @brief Wrapper around the libnm NMActiveConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 21/Jan/2018
	 */
	class ActiveConnection
	{
		friend class libnm::Client;
	public:
		ActiveConnection( const libnm::ActiveConnection& other );
		ActiveConnection( libnm::ActiveConnection&& other );
		libnm::ActiveConnection& operator=( const libnm::ActiveConnection& other );
		libnm::ActiveConnection& operator=( libnm::ActiveConnection&& other );
		virtual ~ActiveConnection();

		NMActiveConnection* native_handle();
		const NMActiveConnection* native_handle() const;

		const char * getUuid() const;
		const char* getId() const;
	protected:
		ActiveConnection( NMActiveConnection* pActiveConnection, bool adopt=false );
		NMActiveConnection* pActiveConnection_;
	};

} // end of namespace libnm

#endif
