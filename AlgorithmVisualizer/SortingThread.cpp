#include "SortingThread.h"

wxThread::ExitCode SortingThread::Entry()
{
    this->Callback->BackgroundWork();
    return nullptr;
    //return ExitCode();
}
    