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
	/** @brief Mock implementation of the wrapper around the libnm NMConnection structure
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 20/May/2018
	 */
	class Connection
	{
	public:
		Connection( const libnm::Connection& other ) = default;
		Connection( libnm::Connection&& other ) = default;
		libnm::Connection& operator=( const libnm::Connection& other ) = default;
		libnm::Connection& operator=( libnm::Connection&& other ) = default;
		virtual ~Connection();

		NMConnection* native_handle();
		const NMConnection* native_handle() const;

		void addSetting( libnm::Setting&& setting );
		const char * getUuid() const;
		const char* getId() const;
	protected:
	};

} // end of namespace libnm

#endif
