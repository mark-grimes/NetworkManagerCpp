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
		// Extra methods to set up mocking behaviour
		template<typename ssid_type,typename bssid_type>
		AccessPoint( ssid_type&& ssid, bssid_type&& bssid, uint32_t maxBitrate, uint8_t strength )
			: ssid_( std::forward<ssid_type>(ssid) ),
			  bssid_( std::forward<bssid_type>(bssid) ),
			  maxBitrate_(maxBitrate),
			  strength_(strength)
		{ /* No operation besides the initialiser list */ }
	protected:
		std::vector<uint8_t> ssid_;
		const std::string bssid_;
		uint32_t maxBitrate_;
		uint8_t strength_;
	};

} // end of namespace libnm

#endif
