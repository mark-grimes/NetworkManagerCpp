#ifndef INCLUDEGUARD_libnm_AccessPoint_h
#define INCLUDEGUARD_libnm_AccessPoint_h

#include <vector>
#include <cstdint>
#include <string>
//
// Forward declarations
//
struct _NMAccessPoint;
typedef struct _NMAccessPoint NMAccessPoint;
namespace libnm
{
	class Connection;
}

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
		AccessPoint( const libnm::AccessPoint& other );
		AccessPoint( libnm::AccessPoint&& other );
		libnm::AccessPoint& operator=( const libnm::AccessPoint& other );
		libnm::AccessPoint& operator=( libnm::AccessPoint&& other );
		virtual ~AccessPoint();

		unsigned getFlags() const;
		unsigned getWPAFlags() const;
		unsigned getRSNFlags() const;
		std::vector<uint8_t> getSSID() const;
		std::string getSSIDString() const;
		const char* getBSSID() const;
		uint32_t getMaxBitrate() const;
		uint8_t getStrength() const;
		bool connectionValid( libnm::Connection& connection ) const;
	protected:
		NMAccessPoint* pAccessPoint_;
	};

} // end of namespace libnm

#endif
