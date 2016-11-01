//
// Created by raeste on 30.10.16.
//

#include "DiningPhilosopher/Semaphor.h"

Semaphor::Semaphor(size_t co) : count(co){}

void Semaphor::release() {
    std::unique_lock<std::mutex> lock(mutex);
    count++;
    conditionVariable.notify_one();
}

void Semaphor::acquire() {
    std::unique_lock<std::mutex> lock(mutex);

    while(count == 0) {
        conditionVariable.wait(lock);
    }

    count--;
}