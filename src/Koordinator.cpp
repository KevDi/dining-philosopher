//
// Created by raeste on 05.11.16.
//

#include "DiningPhilosopher/Koordinator.h"

Koordinator::Koordinator(size_t amountOfPhilosophers) : philosophersCount(amountOfPhilosophers) {
    readyToEatCondition = std::vector<std::condition_variable>(amountOfPhilosophers);
    for(auto i = 0; i < amountOfPhilosophers; i++) {
        forks.push_back(2);
    }
}

void Koordinator::takeForks(size_t id) {
    std::unique_lock<std::mutex> lck(lock);
    while(forks[id] != 2) {
        readyToEatCondition[id].wait(lck);
    }
    forks[(id + 1) % philosophersCount] =  forks[(id + 1)%philosophersCount] - 1;
    forks[(id - 1 + philosophersCount) % philosophersCount] = forks[(id - 1 + philosophersCount) % philosophersCount] -1;
}

void Koordinator::releaseForks(size_t id) {
    std::unique_lock<std::mutex> lck(lock);
    forks[(id +1) % philosophersCount] =  forks[(id + 1)%philosophersCount] + 1;
    forks[((id - 1) + philosophersCount) % philosophersCount] = forks[((id - 1) + philosophersCount) % philosophersCount] + 1;

    if(forks[(id +1) % philosophersCount] == 2) {
        readyToEatCondition[(id +1) % philosophersCount].notify_all();
    }
    if(forks[((id - 1) + philosophersCount) % philosophersCount] == 2) {
        readyToEatCondition[((id - 1) + philosophersCount) % philosophersCount].notify_all();
    }
}
