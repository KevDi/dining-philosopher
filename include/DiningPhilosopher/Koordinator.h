//
// Created by raeste on 05.11.16.
//

#ifndef DININGPHILOSOPHER_KOORDINATOR_H
#define DININGPHILOSOPHER_KOORDINATOR_H


#include <mutex>
#include <condition_variable>
#include <vector>

class Koordinator {
public:
    Koordinator(size_t);
    void takeForks(size_t);
    void releaseForks(size_t);
private:
    std::vector<int> forks;
    size_t philosophersCount;
    std::mutex lock;
    std::vector<std::condition_variable> readyToEatCondition;
};


#endif //DININGPHILOSOPHER_KOORDINATOR_H
