//
// Created by raeste on 05.11.16.
//

#ifndef DININGPHILOSOPHER_WAITRELEASEPHILOSOPH_H
#define DININGPHILOSOPHER_WAITRELEASEPHILOSOPH_H


#include "philosoph.h"

class WaitReleasePhilosoph : public Philosoph {
public:
    WaitReleasePhilosoph(size_t, Fork&, Fork&);
    virtual void operator()() override ;
    virtual ~WaitReleasePhilosoph();

};


#endif //DININGPHILOSOPHER_WAITRELEASEPHILOSOPH_H
