//
// Created by raeste on 05.11.16.
//

#include "DiningPhilosopher/LLRPhilosoph.h"

LLRPhilosoph::LLRPhilosoph(size_t id, Fork& lFork, Fork& rFork ):Philosoph(id, lFork,rFork){
}

void LLRPhilosoph::operator()() {
    while(isRunning) {
        think();
        if(id % 3 == 0) {
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

LLRPhilosoph::~LLRPhilosoph() {

}
