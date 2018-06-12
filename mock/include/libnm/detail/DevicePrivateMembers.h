#pragma once

#include <string>
#include "libnm/Device.h"
#include "libnm/AccessPoint.h"

namespace libnm
{
	namespace detail
	{
		/** @brief Struct only in the mock implementation so that Device and DeviceWifi can be
		 * converted back and forth and still hold the same data.
		 *
		 * @author Mark Grimes (mark.grimes@rymapt.com)
		 * @date 29/May/2018
		 */
		struct DevicePrivateMembers
		{
			libnm::Device::DeviceType type_;
			std::string interface_;
			std::string driver_;
			std::string ipAddress_;
			std::vector<libnm::AccessPoint> accessPoints_;
		};
	} // end of namespace detail
} // end of namespace libnm
