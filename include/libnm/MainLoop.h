#ifndef INCLUDEGUARD_libnm_MainLoop_h
#define INCLUDEGUARD_libnm_MainLoop_h

#include <thread>
//
// Forward declarations
//
struct _GMainLoop;
typedef struct _GMainLoop GMainLoop;
namespace libnm
{
	class Client;
}

namespace libnm
{
	/** @brief Used internally by NetworkManagerCpp. Should not be used by client code.
	 *
	 * @author Mark Grimes (mark.grimes@rymapt.com)
	 * @date 12/Jun/2018
	 */
	class MainLoop
	{
		friend class libnm::Client;
	public:
		~MainLoop();		
	protected:
		MainLoop();
		MainLoop( const libnm::MainLoop& other ) = delete;
		MainLoop( libnm::MainLoop&& other ) = delete;
		libnm::MainLoop& operator=( const libnm::MainLoop& other ) = delete;
		libnm::MainLoop& operator=( libnm::MainLoop&& other ) = delete;
		GMainLoop* pMainLoop_;
		std::thread loopThread_;
	};

} // end of namespace libnm

#endif
