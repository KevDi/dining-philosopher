//
// Created by raeste on 05.11.16.
//

#ifndef DININGPHILOSOPHER_LRPHILOSOPH_H
#define DININGPHILOSOPHER_LRPHILOSOPH_H


#include "philosoph.h"

class LRPhilosoph : public Philosoph {
public:
    LRPhilosoph(size_t, Fork&, Fork&);
    virtual void operator()() override;
    virtual ~LRPhilosoph();
};


#endif //DININGPHILOSOPHER_LRPHILOSOPH_H
