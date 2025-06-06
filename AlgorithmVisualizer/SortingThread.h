#pragma once
#include<wx/thread.h>

class SortingCallback {
public:
	virtual void BackgroundWork() = 0;
};

class SortingThread : wxThread
{
private:
	SortingCallback* Callback;
protected:
	virtual ExitCode Entry();	
public:
	SortingThread(SortingCallback* callback) : Callback(callback) {}
	virtual ~SortingThread() {}
	
};

