#include <iostream>
#include "libnm/Client.h"
#include "libnm/SimpleConnection.h"
#include "libnm/RemoteConnection.h"
#include "libnm/SettingWireless.h"
#include "libnm/SettingWirelessSecurity.h"

void printConnections( const libnm::Client& client )
{
	for( const auto& connection : client.getConnections() )
	{
		std::cout << "\t" << connection.getId() << "\t" << connection.getUuid() << "\n";
	}
}

libnm::RemoteConnection addConnection( libnm::Client& client, const std::string& name, const std::string& SSID, const std::string& password )
{
	libnm::SettingWireless settingWireless;
	settingWireless.setSSID( SSID );
	settingWireless.setMode( libnm::SettingWireless::Mode::INFRA );

	libnm::SettingWirelessSecurity settingWirelessSecurity;
	settingWirelessSecurity.setPSK( password );
	settingWirelessSecurity.setKeyMgmt( libnm::SettingWirelessSecurity::KeyMgmt::WPA_PSK );

	libnm::SimpleConnection connection( name, libnm::SimpleConnection::ConnectionType::WIRELESS );
	connection.addSetting( std::move(settingWireless) );
	connection.addSetting( std::move(settingWirelessSecurity) );

	return client.addConnection( connection );
}

bool deleteConnection( libnm::Client& client, const std::string& UUID )
{
	for( auto& connection : client.getConnections() )
	{
		if( connection.getUuid() == UUID )
		{
			std::cout << "Deleting connection '" << connection.getId() << "' with UUID " << connection.getUuid() << "\n";
			connection.deleteConnection();
		}
	}
}

int main( int argc, char* argv[] )
{
	try
	{
		libnm::Client client;
		std::cout << "Connections before:" << "\n";
		printConnections( client );

		libnm::RemoteConnection newConnection=addConnection( client, "Test WiFi connection", "foobar", "passw0rd" );

		std::cout << "Connections After:" << "\n";
		printConnections( client );

		// Could easily call newConnection.deleteConnection(), but for demonstration purposes show
		// searching for a specific connection to delete.
		deleteConnection( client, newConnection.getUuid() );
	}
	catch( const std::exception& error )
	{
		std::cerr << "Got exception: " << error.what() << std::endl;
		return -1;
	}
}
