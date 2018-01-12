#include "libnm/AccessPoint.h"
#include <NetworkManager.h>

libnm::AccessPoint::AccessPoint( NMAccessPoint* pAccessPoint )
	: pAccessPoint_( pAccessPoint )
{
	//g_object_ref(pAccessPoint_);
}

libnm::AccessPoint::~AccessPoint()
{
	//g_object_unref(pAccessPoint_);
}

std::vector<uint8_t> libnm::AccessPoint::getSSID() const
{
	GBytes* pSSIDBytes=nm_access_point_get_ssid( pAccessPoint_ );
	if( pSSIDBytes==nullptr ) return std::vector<uint8_t>();

	const uint8_t* pStart=reinterpret_cast<const uint8_t*>( g_bytes_get_data(pSSIDBytes,nullptr) );
	const uint8_t* pEnd=pStart+g_bytes_get_size(pSSIDBytes);
	return std::vector<uint8_t>( pStart, pEnd );
}

std::string libnm::AccessPoint::getSSIDString() const
{
	GBytes* pSSIDBytes=nm_access_point_get_ssid( pAccessPoint_ );
	if( pSSIDBytes==nullptr ) return "";
	char* pSSIDString=nm_utils_ssid_to_utf8( reinterpret_cast<const unsigned char*>(g_bytes_get_data(pSSIDBytes,nullptr)), g_bytes_get_size(pSSIDBytes) );
	std::string returnValue( pSSIDString );
	g_free( pSSIDString );
	return returnValue;
}

const char* libnm::AccessPoint::getBSSID() const
{
	return nm_access_point_get_bssid(pAccessPoint_);
}
