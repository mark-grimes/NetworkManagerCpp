#include "libnm/Setting.h"
#include "libnm/detail/SettingPrivateMembers.h"

libnm::Setting::Setting()
	: pData_( std::make_shared<libnm::detail::SettingPrivateMembers>() )
{
}

libnm::Setting::~Setting()
{
}

NMSetting* libnm::Setting::native_handle()
{
	throw std::logic_error("libnm::Setting::native_handle() has not been implemented for the mock classes");
}

const NMSetting* libnm::Setting::native_handle() const
{
	throw std::logic_error("libnm::Setting::native_handle() has not been implemented for the mock classes");
}

void libnm::Setting::invalidate()
{
	throw std::logic_error("libnm::Setting::invalidate() has not been implemented for the mock classes");
}
