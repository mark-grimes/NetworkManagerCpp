#include "libnm/Setting.h"
#include <NetworkManager.h>

libnm::Setting::Setting( NMSetting* pSetting )
	: pSetting_(pSetting)
{
	if( pSetting_ ) g_object_ref(pSetting_);
}

libnm::Setting::Setting( const libnm::Setting& other )
{
	pSetting_=other.pSetting_;
	if( pSetting_ ) g_object_ref(pSetting_);
}

libnm::Setting::Setting( libnm::Setting&& other )
{
	pSetting_=other.pSetting_;
	other.pSetting_=nullptr;
}

libnm::Setting& libnm::Setting::operator=( const libnm::Setting& other )
{
	pSetting_=other.pSetting_;
	if( pSetting_ ) g_object_ref(pSetting_);
	return *this;
}

libnm::Setting& libnm::Setting::operator=( libnm::Setting&& other )
{
	pSetting_=other.pSetting_;
	other.pSetting_=nullptr;
	return *this;
}

libnm::Setting::~Setting()
{
	if( pSetting_ ) g_object_unref(pSetting_);
}

NMSetting* libnm::Setting::native_handle()
{
	return pSetting_;
}

const NMSetting* libnm::Setting::native_handle() const
{
	return pSetting_;
}

void libnm::Setting::invalidate()
{
	pSetting_=nullptr;
}
