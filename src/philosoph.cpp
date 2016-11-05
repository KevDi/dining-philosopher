//
// Created by raeste on 29.10.16.
//
#include "DiningPhilosopher/philosoph.h"

Philosoph::Philosoph(size_t id, Fork& lFork, Fork& rFork) : id(id), leftFork(lFork), rightFork(rFork), eatCounter(0) {

}

void Philosoph::eat() {
    eatCounter++;
    std::this_thread::sleep_for(std::chrono::milliseconds(eatTimeInSec));
}

void Philosoph::think() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(thinkTimeInSec));
}

void Philosoph::stop() {
    isRunning = false;
}

size_t Philosoph::getEatCounter() const {
    return eatCounter;
}

size_t Philosoph::getId() const {
    return id;
}

Philosoph::~Philosoph() {
}
