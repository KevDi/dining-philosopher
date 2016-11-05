//
// Created by raeste on 29.10.16.
//

#ifndef DININGPHILOSOPHER_PHILOSOPH_H
#define DININGPHILOSOPHER_PHILOSOPH_H

#include <thread>
#include <chrono>
#include "Runnable.h"
#include "DiningPhilosopher/Fork.h"
#include "DiningPhilosopher/Globals.h"

class Philosoph : public Runnable {
public:
    Philosoph(size_t, Fork&, Fork&);
    void eat();
    void think() const;
    void stop();
    size_t getEatCounter() const;
    size_t getId() const;
    virtual void operator()() override = 0;
    virtual ~Philosoph();

protected:
    bool isRunning {true};
    const size_t id = 0;
    size_t eatCounter = 0;
    Fork& leftFork;
    Fork& rightFork;

};

#endif //DININGPHILOSOPHER_PHILOSOPH_H
