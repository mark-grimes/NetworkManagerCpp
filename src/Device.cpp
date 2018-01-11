#include "libnm/Device.h"
#include <NetworkManager.h>

libnm::Device::Device( NMDevice* pDevice )
	: pDevice_(pDevice)
{
	//g_object_ref(pDevice_);
}

libnm::Device::~Device()
{
	//g_object_unref(pDevice_);
}
