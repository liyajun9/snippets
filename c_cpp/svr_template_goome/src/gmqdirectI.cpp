#include "gmqdirectI.h"


bool GMQDirectSendI::writeMessages(
        const std::pair<GMQDirect::Table::const_iterator, GMQDirect::Table::const_iterator> &,
        const Ice::Current &)
{
    return false;
}

bool GMQDirectSendI::writeMessagesToIPPort(
        const std::pair<GMQDirect::Table::const_iterator, GMQDirect::Table::const_iterator> &,
        const std::string &, const std::string &, Ice::Long, const Ice::Current &)
{
    return false;
}

bool GMQDirectSendI::writeMessagesFromTo(
        const std::pair<GMQDirect::Table::const_iterator, GMQDirect::Table::const_iterator> &,
        const std::string &, const std::string &, const Ice::Current &)
{
    return false;
}

bool GMQDirectSendI::writeMessagesFrom(const std::string &,
                                       const std::pair<GMQDirect::Table::const_iterator, GMQDirect::Table::const_iterator> &,
                                       const std::string &, const Ice::Current &)
{
    return false;
}

Ice::Long GMQDirectSendI::writeStringsFromTo(
        const std::pair<GMQDirect::StrSeq::const_iterator, GMQDirect::StrSeq::const_iterator> &,
        const std::string &, const std::string &, Ice::Long, Ice::Long, const Ice::Current &)
{
    return 0;
}

Ice::Long GMQDirectSendI::writeStringsToIPPort(
        const std::pair<GMQDirect::StrSeq::const_iterator, GMQDirect::StrSeq::const_iterator> &,
        const std::string &, const std::string &, const std::string &, Ice::Long, const Ice::Current &)
{
    return 0;
}
