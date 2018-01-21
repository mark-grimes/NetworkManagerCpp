#include <iostream>
#include <thread>
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

int main( int argc, char* argv[] )
{
	try
	{
		libnm::Client client;
		std::cout << "Connections before:" << "\n";
		printConnections( client );

		libnm::SettingWireless settingWireless;
		settingWireless.setSSID( "foobar" );
		settingWireless.setMode( libnm::SettingWireless::Mode::INFRA );

		libnm::SettingWirelessSecurity settingWirelessSecurity;
		settingWirelessSecurity.setPSK( "passw0rd" );
		settingWirelessSecurity.setKeyMgmt( libnm::SettingWirelessSecurity::KeyMgmt::WPA_PSK );

		libnm::SimpleConnection connection( "Blah", libnm::SimpleConnection::ConnectionType::WIRELESS );
		connection.addSetting( std::move(settingWireless) );
		connection.addSetting( std::move(settingWirelessSecurity) );

		client.addConnection( connection );

		std::cout << "Connections After:" << "\n";
		printConnections( client );
	}
	catch( const std::exception& error )
	{
		std::cerr << "Got exception: " << error.what() << std::endl;
		return -1;
	}
}
