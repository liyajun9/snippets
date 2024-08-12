#include "ThreadGmqProcessor.h"
#include "globals.h"

ThreadGmqProcessor::ThreadGmqProcessor(size_t nWarningThreshold) : m_bStop(false), m_nWarningThreshold()
{
}

ThreadGmqProcessor::~ThreadGmqProcessor()
{
    stop();
}

int ThreadGmqProcessor::process()
{
    return 0;
}

void ThreadGmqProcessor::run()
{
    while(!m_bStop)
    {
        std::vector<std::string> msgVec;

        if (m_msgVec.empty())
        {
            IceUtil::Monitor<IceUtil::Mutex>::Lock lock(m_monitor);
            if(!m_monitor.timedWait(IceUtil::Time::milliSeconds(1000)))
            {
                continue;
            }
            msgVec.swap(m_msgVec);
        }
        else
        {
            IceUtil::Monitor<IceUtil::Mutex>::Lock lock(m_monitor);
            msgVec.swap(m_msgVec);
        }

        for (auto itr = msgVec.begin(); itr != msgVec.end(); ++itr)
        {
            process();
        }

    }
}

void ThreadGmqProcessor::AddMsg(
        const std::pair<GMQDirect::StrSeq::const_iterator, GMQDirect::StrSeq::const_iterator> &strs)
{
    IceUtil::Monitor<IceUtil::Mutex>::Lock lock(m_monitor);
    m_msgVec.insert(m_msgVec.end(), strs.first, strs.second);
    if (m_nWarningThreshold <= m_msgVec.size())
    {
        MYLOG_ERROR(g_logger, "Cached gmq message size(%zu) exceeds warningThreshold(%zu)", m_msgVec.size(), m_nWarningThreshold);
    }
    m_monitor.notify();
}

void ThreadGmqProcessor::stop()
{
    m_bStop = true;
    m_monitor.notify();
}

