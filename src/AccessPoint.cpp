#include "libnm/AccessPoint.h"
#include <NetworkManager.h>

libnm::AccessPoint::AccessPoint( NMAccessPoint* pAccessPoint )
	: pAccessPoint_( pAccessPoint )
{
	//g_object_ref(pAccessPoint_);
}

libnm::AccessPoint::~AccessPoint()
{
	//g_object_unref(pAccessPoint_);
}
