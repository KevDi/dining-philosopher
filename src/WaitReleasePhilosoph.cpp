//
// Created by raeste on 05.11.16.
//

#include "DiningPhilosopher/WaitReleasePhilosoph.h"

WaitReleasePhilosoph::WaitReleasePhilosoph(size_t id, Fork& lFork, Fork& rFork) : Philosoph(id,rFork,lFork) {
}

void WaitReleasePhilosoph::operator()() {
    while(isRunning) {
        think();
        if(id % 2 == 0) {
            bool lockTest = true;
            do {
                rightFork.mutex.lock();
                if(!leftFork.mutex.try_lock()) {
                    rightFork.mutex.unlock();
                } else {
                    lockTest = false;
                }
            } while (lockTest);
        } else {
            bool lockTest = true;
            do {
                leftFork.mutex.lock();
                if(!rightFork.mutex.try_lock()) {
                    leftFork.mutex.unlock();
                } else {
                    lockTest = false;
                }
            } while (lockTest);
        }
        eat();
        leftFork.mutex.unlock();
        rightFork.mutex.unlock();
    }
}

WaitReleasePhilosoph::~WaitReleasePhilosoph() {

}

