#ifndef INCLUDEGUARD_libnm_version_h
#define INCLUDEGUARD_libnm_version_h

#include <iosfwd>

namespace libnm
{
	namespace version
	{
		extern const char* GitDescribe;
		extern const char GitHash[41];

	} // end of namespace version
} // end of namespace libnm

#endif
