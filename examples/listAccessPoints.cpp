#include <iostream>
#include "libnm/Client.h"
#include "libnm/DeviceWifi.h"
#include "libnm/AccessPoint.h"

int main( int argc, char* argv[] )
{
	try
	{
		libnm::Client client;
		for( auto& device : client.getDevices() )
		{
			if( device.type() == libnm::Device::DeviceType::WIFI )
			{
				std::cout << "Access points for WiFi device " << device.getIface() << ":\n";
				libnm::DeviceWifi wifiDevice=device.asDeviceWifi();
				for( const auto& accessPoint : wifiDevice.getAccessPoints() )
				{
					std::cout << "\tBSSID '" << accessPoint.getBSSID() << "'"
						<< " \tstrength " << (int)accessPoint.getStrength()
						<< " \tmax bit rate " << accessPoint.getMaxBitrate()
						<< " \tSSID '" << accessPoint.getSSIDString() << "'"
						<< " \tflags " << accessPoint.getFlags()
						<< " \tWPA flags " << accessPoint.getWPAFlags()
						<< " \tRSN flags " << accessPoint.getRSNFlags()
						<< "\n";
				} // end of loop over access points
			}
			else std::cout << "Device " << device.getIface() << " is not a WiFi device\n";
		} // end of loop over devices
	}
	catch( const std::exception& error )
	{
		std::cerr << "Got exception: " << error.what() << std::endl;
		return -1;
	}
}
