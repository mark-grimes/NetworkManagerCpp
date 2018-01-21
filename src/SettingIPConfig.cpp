#include "libnm/SettingIPConfig.h"
#include <stdexcept>
#include <NetworkManager.h>

namespace // Unnamed namespace
{
	/** @brief Releases the GError when it goes out of scope
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 21/Jan/2018
	 */
	struct Error
	{
		GError* pError=nullptr;
		~Error() { if( pError ) g_error_free( pError ); }
		operator GError**() { return &pError; } // Automatic conversion for NM functions
		operator bool() { return pError!=nullptr; } // For use in "if( error )" statements
	};
} // end of the unnamed namespace

libnm::SettingIPConfig::SettingIPConfig( NMSettingIPConfig* pSettingIPConfig )
	: Setting( reinterpret_cast<NMSetting*>(pSettingIPConfig) )
{
}

libnm::SettingIPConfig::~SettingIPConfig()
{
}

void libnm::SettingIPConfig::addAddress( const char* address, int prefix )
{
	Error addressError;
	NMIPAddress* pAddress=nm_ip_address_new( this->family(), address, prefix, addressError );
	if( addressError ) throw std::runtime_error(addressError.pError->message);

	nm_setting_ip_config_add_address( reinterpret_cast<NMSettingIPConfig*>(pSetting_), pAddress );
}
