//
// Created by raeste on 30.10.16.
//

#ifndef DININGPHILOSOPHER_SEMAPHILOSOPH_H
#define DININGPHILOSOPHER_SEMAPHILOSOPH_H

#include "DiningPhilosopher/philosoph.h"
#include "DiningPhilosopher/Semaphor.h"


class SemaPhilosoph : public  Philosoph {
public:
    SemaPhilosoph(size_t, Fork&,Fork&, Semaphor&);
    virtual void operator()() override;
    virtual ~SemaPhilosoph();
private:
    Semaphor& semaphor;

};


#endif //DININGPHILOSOPHER_SEMAPHILOSOPH_H
