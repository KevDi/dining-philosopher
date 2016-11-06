//
// Created by raeste on 06.11.16.
//

#include <random>
#include "DiningPhilosopher/RandomWaitReleasePhilosoph.h"

int intRand(const int&, const int&);

RandomWaitReleasePhilosoph::RandomWaitReleasePhilosoph(size_t id, Fork& lFork, Fork& rFork) : Philosoph(id, lFork, rFork) {

}

void RandomWaitReleasePhilosoph::operator()() {
    while(isRunning) {
        think();
        bool lockTest = true;
        do {
            int dice = intRand(0,1);
            if (dice == 0) {
                leftFork.mutex.lock();
                if(!rightFork.mutex.try_lock()) {
                    leftFork.mutex.unlock();
                } else {
                    lockTest = false;
                }
            } else {
                rightFork.mutex.lock();
                if(!leftFork.mutex.try_lock()) {
                    rightFork.mutex.unlock();
                } else {
                    lockTest = false;
                }
            }
        } while (lockTest);
        eat();
        leftFork.mutex.unlock();
        rightFork.mutex.unlock();
    }
}

RandomWaitReleasePhilosoph::~RandomWaitReleasePhilosoph() {

}


int intRand(const int& min, const int& max) {
    static thread_local std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}