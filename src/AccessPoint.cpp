#include "libnm/AccessPoint.h"
#include "libnm/Connection.h"
#include <NetworkManager.h>

libnm::AccessPoint::AccessPoint( NMAccessPoint* pAccessPoint )
	: pAccessPoint_(pAccessPoint)
{
	g_object_ref(pAccessPoint_);
}

libnm::AccessPoint::AccessPoint( const libnm::AccessPoint& other )
{
	pAccessPoint_=other.pAccessPoint_;
	if( pAccessPoint_ ) g_object_ref(pAccessPoint_);
}

libnm::AccessPoint::AccessPoint( libnm::AccessPoint&& other )
{
	pAccessPoint_=other.pAccessPoint_;
	other.pAccessPoint_=nullptr;
}

libnm::AccessPoint& libnm::AccessPoint::operator=( const libnm::AccessPoint& other )
{
	pAccessPoint_=other.pAccessPoint_;
	if( pAccessPoint_ ) g_object_ref(pAccessPoint_);
	return *this;
}

libnm::AccessPoint& libnm::AccessPoint::operator=( libnm::AccessPoint&& other )
{
	pAccessPoint_=other.pAccessPoint_;
	other.pAccessPoint_=nullptr;
	return *this;
}

libnm::AccessPoint::~AccessPoint()
{
	if( pAccessPoint_ ) g_object_unref(pAccessPoint_);
}

NMAccessPoint* libnm::AccessPoint::native_handle()
{
	return pAccessPoint_;
}

const NMAccessPoint* libnm::AccessPoint::native_handle() const
{
	return pAccessPoint_;
}

unsigned libnm::AccessPoint::getFlags() const
{
	return nm_access_point_get_flags( pAccessPoint_ );
}

unsigned libnm::AccessPoint::getWPAFlags() const
{
	return nm_access_point_get_wpa_flags( pAccessPoint_ );
}

unsigned libnm::AccessPoint::getRSNFlags() const
{
	return nm_access_point_get_rsn_flags( pAccessPoint_ );
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

uint32_t libnm::AccessPoint::getMaxBitrate() const
{
	return nm_access_point_get_max_bitrate(pAccessPoint_);
}

uint8_t libnm::AccessPoint::getStrength() const
{
	return nm_access_point_get_strength(pAccessPoint_);
}

bool libnm::AccessPoint::connectionValid( libnm::Connection& connection ) const
{
	return nm_access_point_connection_valid( pAccessPoint_, connection.native_handle() );
}
