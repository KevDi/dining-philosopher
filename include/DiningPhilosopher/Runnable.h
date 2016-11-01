//
// Created by raeste on 29.10.16.
//

#ifndef DININGPHILOSOPHER_RUNNABLE_H
#define DININGPHILOSOPHER_RUNNABLE_H


class Runnable {
public:
    virtual void operator()() = 0;
    virtual ~Runnable();
};


#endif //DININGPHILOSOPHER_RUNNABLE_H
