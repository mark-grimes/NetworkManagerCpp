#ifndef INCLUDEGUARD_libnm_AccessPoint_h
#define INCLUDEGUARD_libnm_AccessPoint_h

#include <vector>
#include <cstdint>
#include <string>

namespace libnm
{
	/** @brief Mock version of AccessPoint
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 20/May/2018
	 */
	class AccessPoint
	{
	public:
		AccessPoint( const libnm::AccessPoint& other ) = default;
		AccessPoint( libnm::AccessPoint&& other ) = default;
		libnm::AccessPoint& operator=( const libnm::AccessPoint& other ) = default;
		libnm::AccessPoint& operator=( libnm::AccessPoint&& other ) = default;
		virtual ~AccessPoint();

		std::vector<uint8_t> getSSID() const;
		std::string getSSIDString() const;
		const char* getBSSID() const;
		uint32_t getMaxBitrate() const;
		uint8_t getStrength() const;
	public:
		AccessPoint(); ///< N.B. Not part of the non-mock class
	};

} // end of namespace libnm

#endif
