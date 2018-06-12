#include "libnm/Device.h"
#include <stdexcept>
#include "libnm/DeviceWifi.h"
#include "libnm/ActiveConnection.h"
#include "libnm/detail/DevicePrivateMembers.h"

libnm::Device::Device( libnm::Device::DeviceType type, const std::string& interface, const std::string& driver )
	: pData_( std::make_shared<libnm::detail::DevicePrivateMembers>() )
{
	pData_->type_=type;
	pData_->interface_=interface;
	pData_->driver_=driver;
	pData_->ipAddress_="169.254.0.23"; // Arbitrary rubbish
}

libnm::Device::Device( std::shared_ptr<libnm::detail::DevicePrivateMembers> pData ) : pData_(pData)
{
}

libnm::Device::~Device()
{
}

libnm::Device::DeviceType libnm::Device::type() const
{
	return pData_->type_;
}

libnm::DeviceWifi libnm::Device::asDeviceWifi()
{
	if( pData_->type_!=DeviceType::WIFI ) throw std::runtime_error("Device::asDeviceWifi called on a non-WIFI device");
	return libnm::DeviceWifi( pData_ );
}

const char* libnm::Device::getIface() const
{
	return pData_->interface_.c_str();
}

const char* libnm::Device::getDriver() const
{
	return pData_->driver_.c_str();
}

const char* libnm::Device::getIPIface() const
{
	return pData_->ipAddress_.c_str();
}

libnm::ActiveConnection libnm::Device::getActiveConnection()
{
	throw std::logic_error("libnm::Device::getActiveConnection() has not been implemented for the mock classes");
}

void libnm::Device::mock_setIPIface( const std::string& address )
{
	pData_->ipAddress_=address;
}
