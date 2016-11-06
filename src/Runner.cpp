//
// Created by raeste on 05.11.16.
//

#include <cstddef>
#include <iostream>
#include <DiningPhilosopher/LRPhilosoph.h>
#include <DiningPhilosopher/LLRPhilosoph.h>
#include <DiningPhilosopher/CoordinatedPhilosopher.h>
#include <DiningPhilosopher/WaitReleasePhilosoph.h>
#include <DiningPhilosopher/RandomWaitReleasePhilosoph.h>
#include "DiningPhilosopher/Semaphor.h"
#include "DiningPhilosopher/ThreadGroup.h"
#include "DiningPhilosopher/SemaPhilosoph.h"

void SemaDinning(const size_t philosophersCount) {
    std::cout<<"Semaphore: "<<std::endl;
    Semaphor semaphor(philosophersCount-1);
    ThreadGroup threadGroup;
    std::cout<<"Create Forks"<<std::endl;
    std::vector<std::unique_ptr<SemaPhilosoph>> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(std::unique_ptr<SemaPhilosoph>(new SemaPhilosoph(i,forks[i],forks[(i+1)%philosophersCount],semaphor)));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto& philosoph : listOfPhilosopher) {
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

}

void LRDinning(const size_t philosophersCount) {
    std::cout<<"LR: "<<std::endl;
    ThreadGroup threadGroup;
    std::cout<<"Create Forks"<<std::endl;
    std::vector<std::unique_ptr<LRPhilosoph>> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(std::unique_ptr<LRPhilosoph>(new LRPhilosoph(i,forks[i],forks[(i+1)%philosophersCount])));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto& philosoph : listOfPhilosopher) {
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
    std::cout<<"LR Gesamt:\t\t "<<gesamt<<std::endl;
}

void LLRDinning(const size_t philosophersCount) {
    std::cout<<"LLR: "<<std::endl;
    ThreadGroup threadGroup;
    std::cout<<"Create Forks"<<std::endl;
    std::vector<std::unique_ptr<LLRPhilosoph>> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(std::unique_ptr<LLRPhilosoph>(new LLRPhilosoph(i,forks[i],forks[(i+1)%philosophersCount])));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto& philosoph : listOfPhilosopher) {
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
    std::cout<<"LLR Gesamt:\t\t "<<gesamt<<std::endl;
}

void CoordinateDinning(const size_t philosophersCount) {
    std::cout<<"Coordinate: "<<std::endl;
    ThreadGroup threadGroup;
    std::cout<<"Create Koordinator"<<std::endl;
    Koordinator koordinator(philosophersCount);
    std::cout<<"Create Forks"<<std::endl;
    std::vector<std::unique_ptr<CoordinatedPhilosopher>> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(std::unique_ptr<CoordinatedPhilosopher>(new CoordinatedPhilosopher(i,forks[i],forks[(i+1)%philosophersCount],koordinator)));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto& philosoph : listOfPhilosopher) {
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
    std::cout<<"Coordinator Gesamt:\t\t "<<gesamt<<std::endl;
}

void WaitReleaseDinning(const size_t philosophersCount) {
    std::cout<<"Wait And Release: "<<std::endl;
    ThreadGroup threadGroup;
    std::cout<<"Create Forks"<<std::endl;
    std::vector<std::unique_ptr<WaitReleasePhilosoph>> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(std::unique_ptr<WaitReleasePhilosoph>(new WaitReleasePhilosoph(i,forks[i],forks[(i+1)%philosophersCount])));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto& philosoph : listOfPhilosopher) {
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
    std::cout<<"Wait and Release Gesamt:\t\t "<<gesamt<<std::endl;
}

void RandomWaitReleaseDinning(const size_t philosophersCount) {
    std::cout<<"Wait And Release: "<<std::endl;
    ThreadGroup threadGroup;
    std::cout<<"Create Forks"<<std::endl;
    std::vector<std::unique_ptr<RandomWaitReleasePhilosoph>> listOfPhilosopher;
    std::vector<Fork> forks(philosophersCount);
    for(size_t i = 0; i < philosophersCount; ++i) {
        listOfPhilosopher.push_back(std::unique_ptr<RandomWaitReleasePhilosoph>(new RandomWaitReleasePhilosoph(i,forks[i],forks[(i+1)%philosophersCount])));
        threadGroup.add_thread(*(listOfPhilosopher[i]));
    }

    std::cout<<"Sleep for 10 seconds"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timeInSec));

    std::cout<<"Finish all threads"<<std::endl;
    for(auto& philosoph : listOfPhilosopher) {
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
    std::cout<<"Random Wait and Release Gesamt:\t\t "<<gesamt<<std::endl;
}