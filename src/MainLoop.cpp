#include "libnm/MainLoop.h"
#include <glib.h>

libnm::MainLoop::MainLoop()
{
	pMainLoop_=g_main_loop_new( nullptr, false );
	loopThread_=std::thread( [this](){ g_main_loop_run(pMainLoop_); } );
}

libnm::MainLoop::~MainLoop()
{
	g_main_loop_quit(pMainLoop_);
	loopThread_.join();
	g_main_loop_unref(pMainLoop_);
}
