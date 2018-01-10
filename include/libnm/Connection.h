#ifndef INCLUDEGUARD_libnm_Connection_h
#define INCLUDEGUARD_libnm_Connection_h

//
// Forward declarations
//
struct _NMConnection;
typedef struct _NMConnection NMConnection;

namespace libnm
{
	/** @brief Wrapper around the libnm NMConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 10/Jan/2018
	 */
	class Connection
 	{
 	public:
 		virtual ~Connection();
 		const char* getId() const;
 	protected:
 		Connection( NMConnection* pConnection );
 		NMConnection* pConnection_;
 	};

} // end of namespace libnm

#endif
