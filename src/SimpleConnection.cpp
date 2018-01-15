#include "libnm/SimpleConnection.h"
#include <stdexcept>
#include <NetworkManager.h>

libnm::SimpleConnection::SimpleConnection( const std::string& name, libnm::SimpleConnection::ConnectionType type )
	: Connection( nullptr )
{
	char const* pType;
	switch( type )
	{
		case ConnectionType::WIRED: pType=NM_SETTING_WIRED_SETTING_NAME; break;
		case ConnectionType::WIRELESS: pType=NM_SETTING_WIRELESS_SETTING_NAME; break;
		default: throw std::runtime_error("SimpleConnection constructed with invalid type");
	}

	pConnection_=nm_simple_connection_new();

	NMSetting* pSetting=nm_setting_connection_new();
	char* pUUID=nm_utils_uuid_generate();
	g_object_set( pSetting,
		NM_SETTING_CONNECTION_UUID, pUUID,
		NM_SETTING_CONNECTION_ID, name.c_str(),
		NM_SETTING_CONNECTION_TYPE, pType,
		NULL );
	g_free(pUUID);
	nm_connection_add_setting( pConnection_, pSetting );
}

libnm::SimpleConnection::~SimpleConnection()
{
}
