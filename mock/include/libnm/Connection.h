#ifndef INCLUDEGUARD_libnm_Connection_h
#define INCLUDEGUARD_libnm_Connection_h

#include <string>
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
		template<typename string_1,typename string_2>
		Connection( string_1&& uuid, string_2&& id )
			: uuid_(std::forward<string_1>(uuid)), id_(std::forward<string_2>(id))
		{ /* No operation */ }
		const std::string uuid_;
		const std::string id_;
	};

} // end of namespace libnm

#endif
