//
// Created by raeste on 05.11.16.
//

#include "DiningPhilosopher/LRPhilosoph.h"

LRPhilosoph::LRPhilosoph(size_t id, Fork& lFork, Fork& rFork) : Philosoph(id, lFork, rFork){}

void LRPhilosoph::operator()() {
    while(isRunning) {
        think();
        if(id % 2 == 0) {
            rightFork.mutex.lock();
            leftFork.mutex.lock();
        } else {
            leftFork.mutex.lock();
            rightFork.mutex.lock();
        }
        eat();
        leftFork.mutex.unlock();
        rightFork.mutex.unlock();
    }
}

LRPhilosoph::~LRPhilosoph() {

}


