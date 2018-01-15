#ifndef INCLUDEGUARD_libnm_Connection_h
#define INCLUDEGUARD_libnm_Connection_h

//
// Forward declarations
//
struct _NMConnection;
typedef struct _NMConnection NMConnection;
namespace libnm
{
	class Setting;
}


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
		Connection( const libnm::Connection& other );
		Connection( libnm::Connection&& other );
		libnm::Connection& operator=( const libnm::Connection& other );
		libnm::Connection& operator=( libnm::Connection&& other );
		virtual ~Connection();

		NMConnection* native_handle();
		const NMConnection* native_handle() const;

		void addSetting( libnm::Setting&& setting );
		const char* getId() const;
	protected:
		Connection( NMConnection* pConnection );
		NMConnection* pConnection_;
	};

} // end of namespace libnm

#endif
