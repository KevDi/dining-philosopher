//
// Created by raeste on 30.10.16.
//

#include "DiningPhilosopher/SemaPhilosoph.h"

SemaPhilosoph::SemaPhilosoph(size_t id, Fork& lFork, Fork& rFork, Semaphor& sema) : Philosoph(id, lFork, rFork), semaphor(sema) {
}

void SemaPhilosoph::operator()() {
    while(isRunning) {
        think();
        semaphor.acquire();
        leftFork.mutex.lock();
        rightFork.mutex.lock();
        eat();
        leftFork.mutex.unlock();
        rightFork.mutex.unlock();
        semaphor.release();
    }
}

SemaPhilosoph::~SemaPhilosoph() {
}