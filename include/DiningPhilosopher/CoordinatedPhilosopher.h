//
// Created by raeste on 05.11.16.
//

#ifndef DININGPHILOSOPHER_COORDINATEDPHILOSOPHER_H
#define DININGPHILOSOPHER_COORDINATEDPHILOSOPHER_H


#include "philosoph.h"
#include "Koordinator.h"

class CoordinatedPhilosopher : public Philosoph {
public:
    CoordinatedPhilosopher(size_t, Fork&, Fork&, Koordinator&);
    virtual void operator()() override ;
    virtual ~CoordinatedPhilosopher();
private:
    Koordinator& coordinator;

};


#endif //DININGPHILOSOPHER_COORDINATEDPHILOSOPHER_H
