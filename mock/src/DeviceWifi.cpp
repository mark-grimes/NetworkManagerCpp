#include "libnm/DeviceWifi.h"
#include "libnm/AccessPoint.h"

libnm::DeviceWifi::~DeviceWifi()
{
}

std::vector<libnm::AccessPoint> libnm::DeviceWifi::getAccessPoints() const
{
	std::vector<libnm::AccessPoint> returnValue;
	return returnValue;
}
