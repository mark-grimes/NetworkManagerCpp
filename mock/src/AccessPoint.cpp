#include "libnm/AccessPoint.h"

libnm::AccessPoint::~AccessPoint()
{
}

std::vector<uint8_t> libnm::AccessPoint::getSSID() const
{
	return { 'S','S','I','D',' ','s','t','r','i','n','g' };
}

std::string libnm::AccessPoint::getSSIDString() const
{
	return "SSID string";
}

const char* libnm::AccessPoint::getBSSID() const
{
	return "A1:B2:C3:D4:E5:F6";
}

uint32_t libnm::AccessPoint::getMaxBitrate() const
{
	return 54000;
}

uint8_t libnm::AccessPoint::getStrength() const
{
	return 80;
}
