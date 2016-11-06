//
// Created by raeste on 05.11.16.
//

#include "DiningPhilosopher/CoordinatedPhilosopher.h"

CoordinatedPhilosopher::CoordinatedPhilosopher(size_t id, Fork& lFork, Fork& rFork, Koordinator& coord) : Philosoph(id,lFork,rFork), coordinator(coord) {}

void CoordinatedPhilosopher::operator()() {
    while(isRunning) {
        think();
        coordinator.takeForks(id);
        eat();
        coordinator.releaseForks(id);
    }
}

CoordinatedPhilosopher::~CoordinatedPhilosopher() {

}
