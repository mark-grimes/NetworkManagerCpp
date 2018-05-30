#include "libnm/AccessPoint.h"

libnm::AccessPoint::~AccessPoint()
{
}

unsigned libnm::AccessPoint::getFlags() const
{
	return 0x01;
}

unsigned libnm::AccessPoint::getWPAFlags() const
{
	return 0x00;
}

unsigned libnm::AccessPoint::getRSNFlags() const
{
	return 0x00;
}

std::vector<uint8_t> libnm::AccessPoint::getSSID() const
{
	return ssid_;
}

std::string libnm::AccessPoint::getSSIDString() const
{
	std::string result;
	for( const auto& byte : ssid_ )
	{
		if( byte>=32 && byte <=126 ) result+=byte;
		else result+='?';
	}
	return result;
}

const char* libnm::AccessPoint::getBSSID() const
{
	return bssid_.c_str();
}

uint32_t libnm::AccessPoint::getMaxBitrate() const
{
	return maxBitrate_;
}

uint8_t libnm::AccessPoint::getStrength() const
{
	return strength_;
}
