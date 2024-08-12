#ifndef SVR_TEMPLATE_GMQDIRECTI_H
#define SVR_TEMPLATE_GMQDIRECTI_H

#include "gmqdirect.h"


class GMQDirectSendI : public GMQDirect::GMQDirectSend
{
public:

    virtual bool writeMessages(const ::std::pair< ::GMQDirect::Table::const_iterator,  ::GMQDirect::Table::const_iterator>&,
                               const Ice::Current&);

    virtual bool writeMessagesToIPPort(const ::std::pair< ::GMQDirect::Table::const_iterator,  ::GMQDirect::Table::const_iterator>&,
                                       const ::std::string&,
                                       const ::std::string&,
                                       ::Ice::Long,
                                       const Ice::Current&);

    virtual bool writeMessagesFromTo(const ::std::pair< ::GMQDirect::Table::const_iterator,  ::GMQDirect::Table::const_iterator>&,
                                     const ::std::string&,
                                     const ::std::string&,
                                     const Ice::Current&);

    virtual bool writeMessagesFrom(const ::std::string&,
                                   const ::std::pair< ::GMQDirect::Table::const_iterator,  ::GMQDirect::Table::const_iterator>&,
                                   const ::std::string&,
                                   const Ice::Current&);

    virtual ::Ice::Long writeStringsFromTo(const ::std::pair< ::GMQDirect::StrSeq::const_iterator,  ::GMQDirect::StrSeq::const_iterator>&,
                                           const ::std::string&,
                                           const ::std::string&,
                                           ::Ice::Long,
                                           ::Ice::Long,
                                           const ::Ice::Current&);

    virtual ::Ice::Long writeStringsToIPPort(const ::std::pair< ::GMQDirect::StrSeq::const_iterator,  ::GMQDirect::StrSeq::const_iterator>&,
                                             const ::std::string&,
                                             const ::std::string&,
                                             const ::std::string&,
                                             ::Ice::Long,
                                             const ::Ice::Current&);
};

typedef IceUtil::Handle<GMQDirectSendI> GMQDirectSendIPtr;


#endif //SVR_TEMPLATE_GMQDIRECTI_H
