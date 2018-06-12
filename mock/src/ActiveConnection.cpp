#include "libnm/ActiveConnection.h"
#include <stdexcept>
#include <iostream>

std::ostream& operator<<( std::ostream& stream, libnm::ActiveConnection::State state )
{
	switch( state )
	{
		case libnm::ActiveConnection::State::UNKNOWN : stream << "ActiveConnection::State::UNKNOWN"; break;
		case libnm::ActiveConnection::State::ACTIVATING : stream << "ActiveConnection::State::ACTIVATING"; break;
		case libnm::ActiveConnection::State::ACTIVATED : stream << "ActiveConnection::State::ACTIVATED"; break;
		case libnm::ActiveConnection::State::DEACTIVATING : stream << "ActiveConnection::State::DEACTIVATING"; break;
		case libnm::ActiveConnection::State::DEACTIVATED : stream << "ActiveConnection::State::DEACTIVATED"; break;
	}
	return stream;
}

std::ostream& operator<<( std::ostream& stream, libnm::ActiveConnection::StateReason reason )
{
	switch( reason )
	{
		case libnm::ActiveConnection::StateReason::UNKNOWN: stream << "ActiveConnection::StateReason::UNKNOWN"; break;
		case libnm::ActiveConnection::StateReason::NONE: stream << "ActiveConnection::StateReason::NONE"; break;
		case libnm::ActiveConnection::StateReason::USER_DISCONNECTED: stream << "ActiveConnection::StateReason::USER_DISCONNECTED"; break;
		case libnm::ActiveConnection::StateReason::DEVICE_DISCONNECTED: stream << "ActiveConnection::StateReason::DEVICE_DISCONNECTED"; break;
		case libnm::ActiveConnection::StateReason::SERVICE_STOPPED: stream << "ActiveConnection::StateReason::SERVICE_STOPPED"; break;
		case libnm::ActiveConnection::StateReason::IP_CONFIG_INVALID: stream << "ActiveConnection::StateReason::IP_CONFIG_INVALID"; break;
		case libnm::ActiveConnection::StateReason::CONNECT_TIMEOUT: stream << "ActiveConnection::StateReason::CONNECT_TIMEOUT"; break;
		case libnm::ActiveConnection::StateReason::SERVICE_START_TIMEOUT: stream << "ActiveConnection::StateReason::SERVICE_START_TIMEOUT"; break;
		case libnm::ActiveConnection::StateReason::SERVICE_START_FAILED: stream << "ActiveConnection::StateReason::SERVICE_START_FAILED"; break;
		case libnm::ActiveConnection::StateReason::NO_SECRETS: stream << "ActiveConnection::StateReason::NO_SECRETS"; break;
		case libnm::ActiveConnection::StateReason::LOGIN_FAILED: stream << "ActiveConnection::StateReason::LOGIN_FAILED"; break;
		case libnm::ActiveConnection::StateReason::CONNECTION_REMOVED: stream << "ActiveConnection::StateReason::CONNECTION_REMOVED"; break;
		case libnm::ActiveConnection::StateReason::DEPENDENCY_FAILED: stream << "ActiveConnection::StateReason::DEPENDENCY_FAILED"; break;
		case libnm::ActiveConnection::StateReason::DEVICE_REALIZE_FAILED: stream << "ActiveConnection::StateReason::DEVICE_REALIZE_FAILED"; break;
		case libnm::ActiveConnection::StateReason::DEVICE_REMOVED: stream << "ActiveConnection::StateReason::DEVICE_REMOVED"; break;
	}
	return stream;
}

NMActiveConnection* libnm::ActiveConnection::native_handle()
{
	throw std::logic_error("libnm::ActiveConnection::native_handle() has not been implemented for the mock classes");
}

const NMActiveConnection* libnm::ActiveConnection::native_handle() const
{
	throw std::logic_error("libnm::ActiveConnection::native_handle() has not been implemented for the mock classes");
}

const char* libnm::ActiveConnection::getUuid() const
{
	throw std::logic_error("libnm::ActiveConnection::getUuid() has not been implemented for the mock classes");
}

const char* libnm::ActiveConnection::getId() const
{
	throw std::logic_error("libnm::ActiveConnection::getId() has not been implemented for the mock classes");
}

libnm::ActiveConnection::State libnm::ActiveConnection::getState() const
{
	throw std::logic_error("libnm::ActiveConnection::getState() has not been implemented for the mock classes");
}

libnm::ActiveConnection::StateReason libnm::ActiveConnection::getStateReason() const
{
	throw std::logic_error("libnm::ActiveConnection::getStateReason() has not been implemented for the mock classes");
}
