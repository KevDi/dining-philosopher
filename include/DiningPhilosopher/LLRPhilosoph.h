//
// Created by raeste on 05.11.16.
//

#ifndef DININGPHILOSOPHER_LLRPHILOSOPH_H
#define DININGPHILOSOPHER_LLRPHILOSOPH_H


#include "philosoph.h"

class LLRPhilosoph : public Philosoph {
public:
    LLRPhilosoph(size_t, Fork &, Fork&);
    virtual void operator()() override;
    virtual ~LLRPhilosoph();

};


#endif //DININGPHILOSOPHER_LLRPHILOSOPH_H
