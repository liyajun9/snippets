#ifndef SVR_TEMPLATE_THREADGMQPROCESSOR_H
#define SVR_TEMPLATE_THREADGMQPROCESSOR_H


#include <IceUtil/Thread.h>
#include <vector>
#include <IceUtil/Monitor.h>
#include "gmqdirectI.h"

class ThreadGmqProcessor : public IceUtil::Thread
{
public:
    ThreadGmqProcessor(size_t nWarningThreshold);
    virtual ~ThreadGmqProcessor();

    virtual void run();
    void AddMsg(const std::pair< GMQDirect::StrSeq::const_iterator,  GMQDirect::StrSeq::const_iterator> & strs);
    void stop();

protected:
    int process();

private:
    bool m_bStop;
    const size_t m_nWarningThreshold;

    IceUtil::Monitor<IceUtil::Mutex> m_monitor;
    std::vector<std::string> m_msgVec;
};

typedef IceUtil::Handle<ThreadGmqProcessor> ThreadGmqProcessorPtr;
#endif //SVR_TEMPLATE_THREADGMQPROCESSOR_H
