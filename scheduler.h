/**
 * File: http-proxy-scheduler.h
 * ----------------------------
 * This class defines the scheduler class, which takes all
 * proxied requests off of the main thread and schedules them to 
 * be handled by a constant number of child threads.
 */

#ifndef _http_proxy_scheduler_
#define _http_proxy_scheduler_

#include <string>
#include "request-handler.h"
#include "thread-pool.h"

const int kMaxThreads = 32;

class HTTPProxyScheduler {
 public:
	
	HTTPProxyScheduler() : workers(kMaxThreads) {}
  	void scheduleRequest(int connectionfd, const std::string& clientIPAddress);

private:
  	
  	HTTPRequestHandler handler;
	ThreadPool workers;
	
};

#endif
