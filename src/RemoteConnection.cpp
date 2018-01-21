#include "libnm/RemoteConnection.h"
#include <stdexcept>
#include <NetworkManager.h>

namespace // Unnamed namespace
{
	/** @brief Releases the GError when it goes out of scope
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 21/Jan/2018
	 */
	struct Error
	{
		GError* pError=nullptr;
		~Error() { if( pError ) g_error_free( pError ); }
		operator GError**() { return &pError; } // Automatic conversion for NM functions
		operator bool() { return pError!=nullptr; } // For use in "if( error )" statements
	};
} // end of the unnamed namespace

libnm::RemoteConnection::RemoteConnection( NMRemoteConnection* pRemoteConnection, bool adopt )
	: Connection( reinterpret_cast<NMConnection*>(pRemoteConnection), adopt )
{
}

libnm::RemoteConnection::~RemoteConnection()
{
}

bool libnm::RemoteConnection::save() const
{
	::Error saveError;
	bool result=nm_remote_connection_save( reinterpret_cast<NMRemoteConnection*>(pConnection_), nullptr, saveError );
	if( saveError ) throw std::runtime_error(saveError.pError->message);
	return result;
}

bool libnm::RemoteConnection::deleteConnection()
{
	::Error deleteError;
	bool result=nm_remote_connection_delete( reinterpret_cast<NMRemoteConnection*>(pConnection_), nullptr, deleteError );
	if( deleteError ) throw std::runtime_error(deleteError.pError->message);
	return result;
}
