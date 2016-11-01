#include <iostream>
#include <vector>
#include <thread>
#include <DiningPhilosopher/ThreadGroup.h>
#include "DiningPhilosopher/Semaphor.h"
#include "DiningPhilosopher/SemaPhilosoph.h"

void dining(size_t philosophersCount);

int main() {
    dining(10);
    return 0;
}


void dining(const size_t philosophersCount) {
    std::cout<<"Semaphore: "<<std::endl;
    Semaphor semaphor(philosophersCount-1);
    ThreadGroup threadGroup;
    std::cout<<"Create Forks"<<std::endl;
    std::vector<SemaPhilosoph*> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(new SemaPhilosoph(i,forks[i],forks[(i+1)%philosophersCount],semaphor));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto philosoph : listOfPhilosopher) {
        philosoph->stop();
    }

    std::cout<<"Joining them"<<std::endl;
    threadGroup.join_all();

    std::cout<<"Calculate overall Eatcounter"<<std::endl;
    size_t gesamt = 0;
    for(const auto& philosoph : listOfPhilosopher) {
        std::cout<<"Philosoph "<<philosoph->getId()<<" eats: "<<philosoph->getEatCounter()<<std::endl;
        gesamt += philosoph->getEatCounter();
    }
    std::cout<<"Semaphore Gesamt:\t\t "<<gesamt<<std::endl;

    for(const auto& philosoph : listOfPhilosopher) {
        delete philosoph;
    }
}