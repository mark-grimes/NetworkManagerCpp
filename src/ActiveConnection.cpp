#include "libnm/ActiveConnection.h"
#include <stdexcept>
#include "libnm/Setting.h"
#include <NetworkManager.h>
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

libnm::ActiveConnection::ActiveConnection( NMActiveConnection* pActiveConnection, bool adopt )
	: pActiveConnection_(pActiveConnection)
{
	if( pActiveConnection_ && !adopt ) g_object_ref(pActiveConnection_);
}

libnm::ActiveConnection::ActiveConnection( const libnm::ActiveConnection& other )
{
	pActiveConnection_=other.pActiveConnection_;
	if( pActiveConnection_ ) g_object_ref(pActiveConnection_);
}

libnm::ActiveConnection::ActiveConnection( libnm::ActiveConnection&& other )
{
	pActiveConnection_=other.pActiveConnection_;
	other.pActiveConnection_=nullptr;
}

libnm::ActiveConnection& libnm::ActiveConnection::operator=( const libnm::ActiveConnection& other )
{
	pActiveConnection_=other.pActiveConnection_;
	if( pActiveConnection_ ) g_object_ref(pActiveConnection_);
	return *this;
}

libnm::ActiveConnection& libnm::ActiveConnection::operator=( libnm::ActiveConnection&& other )
{
	pActiveConnection_=other.pActiveConnection_;
	other.pActiveConnection_=nullptr;
	return *this;
}

libnm::ActiveConnection::~ActiveConnection()
{
	if( pActiveConnection_ ) g_object_unref(pActiveConnection_);
}

NMActiveConnection* libnm::ActiveConnection::native_handle()
{
	return pActiveConnection_;
}

const NMActiveConnection* libnm::ActiveConnection::native_handle() const
{
	return pActiveConnection_;
}

const char* libnm::ActiveConnection::getUuid() const
{
	if( !pActiveConnection_ ) throw std::runtime_error("libnm::ActiveConnection::getUuid() called on invalid ActiveConnection");
	return nm_active_connection_get_uuid(pActiveConnection_);
}

const char* libnm::ActiveConnection::getId() const
{
	if( !pActiveConnection_ ) throw std::runtime_error("libnm::ActiveConnection::getId() called on invalid ActiveConnection");
	return nm_active_connection_get_id(pActiveConnection_);
}

libnm::ActiveConnection::State libnm::ActiveConnection::getState() const
{
	if( !pActiveConnection_ ) throw std::runtime_error("libnm::ActiveConnection::getState() called on invalid ActiveConnection");
	auto state=nm_active_connection_get_state(pActiveConnection_);
	switch( state )
	{
		case NM_ACTIVE_CONNECTION_STATE_UNKNOWN: return ActiveConnection::State::UNKNOWN;
		case NM_ACTIVE_CONNECTION_STATE_ACTIVATING: return ActiveConnection::State::ACTIVATING;
		case NM_ACTIVE_CONNECTION_STATE_ACTIVATED: return ActiveConnection::State::ACTIVATED;
		case NM_ACTIVE_CONNECTION_STATE_DEACTIVATING: return ActiveConnection::State::DEACTIVATING;
		case NM_ACTIVE_CONNECTION_STATE_DEACTIVATED: return ActiveConnection::State::DEACTIVATED;
		default: throw std::runtime_error("libnm::ActiveConnection::getState() got unexpected state value "+std::to_string(state));
	}
}

libnm::ActiveConnection::StateReason libnm::ActiveConnection::getStateReason() const
{
	if( !pActiveConnection_ ) throw std::runtime_error("libnm::ActiveConnection::getStateReason() called on invalid ActiveConnection");
	auto reason=nm_active_connection_get_state_reason(pActiveConnection_);
	switch( reason )
	{
		case NM_ACTIVE_CONNECTION_STATE_REASON_UNKNOWN: return ActiveConnection::StateReason::UNKNOWN;
		case NM_ACTIVE_CONNECTION_STATE_REASON_NONE: return ActiveConnection::StateReason::NONE;
		case NM_ACTIVE_CONNECTION_STATE_REASON_USER_DISCONNECTED: return ActiveConnection::StateReason::USER_DISCONNECTED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_DEVICE_DISCONNECTED: return ActiveConnection::StateReason::DEVICE_DISCONNECTED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_SERVICE_STOPPED: return ActiveConnection::StateReason::SERVICE_STOPPED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_IP_CONFIG_INVALID: return ActiveConnection::StateReason::IP_CONFIG_INVALID;
		case NM_ACTIVE_CONNECTION_STATE_REASON_CONNECT_TIMEOUT: return ActiveConnection::StateReason::CONNECT_TIMEOUT;
		case NM_ACTIVE_CONNECTION_STATE_REASON_SERVICE_START_TIMEOUT: return ActiveConnection::StateReason::SERVICE_START_TIMEOUT;
		case NM_ACTIVE_CONNECTION_STATE_REASON_SERVICE_START_FAILED: return ActiveConnection::StateReason::SERVICE_START_FAILED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_NO_SECRETS: return ActiveConnection::StateReason::NO_SECRETS;
		case NM_ACTIVE_CONNECTION_STATE_REASON_LOGIN_FAILED: return ActiveConnection::StateReason::LOGIN_FAILED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_CONNECTION_REMOVED: return ActiveConnection::StateReason::CONNECTION_REMOVED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_DEPENDENCY_FAILED: return ActiveConnection::StateReason::DEPENDENCY_FAILED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_DEVICE_REALIZE_FAILED: return ActiveConnection::StateReason::DEVICE_REALIZE_FAILED;
		case NM_ACTIVE_CONNECTION_STATE_REASON_DEVICE_REMOVED: return ActiveConnection::StateReason::DEVICE_REMOVED;
		default: throw std::runtime_error("libnm::ActiveConnection::getStateReason() got unexpected reason value "+std::to_string(reason));
	}
}
