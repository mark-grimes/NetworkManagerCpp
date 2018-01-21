#include <iostream>
#include "libnm/Client.h"
#include "libnm/SimpleConnection.h"
#include "libnm/RemoteConnection.h"
#include "libnm/SettingWireless.h"
#include "libnm/SettingWirelessSecurity.h"
#include "libnm/SettingIP4Config.h"

libnm::RemoteConnection createAccessPoint( libnm::Client& client, const std::string& name, const std::string& SSID, const std::string& password )
{
	libnm::SettingWireless settingWireless;
	settingWireless.setSSID( SSID );
	settingWireless.setMode( libnm::SettingWireless::Mode::AP );

	libnm::SettingWirelessSecurity settingWirelessSecurity;
	settingWirelessSecurity.setPSK( password );
	settingWirelessSecurity.setKeyMgmt( libnm::SettingWirelessSecurity::KeyMgmt::WPA_PSK );

	libnm::SettingIP4Config settingIP4Config;
	settingIP4Config.setMethod( libnm::SettingIP4Config::Method::MANUAL );
	settingIP4Config.addAddress( "192.168.0.1", 24 );

	libnm::SimpleConnection connection( name, libnm::SimpleConnection::ConnectionType::WIRELESS );
	connection.addSetting( std::move(settingWireless) );
	connection.addSetting( std::move(settingWirelessSecurity) );
	connection.addSetting( std::move(settingIP4Config) );

	return client.addConnection( connection );
}

int main( int argc, char* argv[] )
{
	try
	{
		libnm::Client client;
		libnm::RemoteConnection accessPoint=createAccessPoint( client, "My access point", "MG-AP", "passw0rd" );
		//accessPoint.save();
	}
	catch( const std::exception& error )
	{
		std::cerr << "Got exception: " << error.what() << std::endl;
		return -1;
	}
}
