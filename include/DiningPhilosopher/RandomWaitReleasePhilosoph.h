//
// Created by raeste on 06.11.16.
//

#ifndef DININGPHILOSOPHER_RANDOMWAITRELEASEPHILOSOPH_H
#define DININGPHILOSOPHER_RANDOMWAITRELEASEPHILOSOPH_H


#include <vector>
#include "philosoph.h"

class RandomWaitReleasePhilosoph : public Philosoph {
public:
    RandomWaitReleasePhilosoph(size_t,Fork&,Fork&);
    virtual void operator()() override;
    virtual ~RandomWaitReleasePhilosoph();
};


#endif //DININGPHILOSOPHER_RANDOMWAITRELEASEPHILOSOPH_H
