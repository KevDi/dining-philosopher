//
// Created by raeste on 30.10.16.
//

#ifndef DININGPHILOSOPHER_SEMAPHOR_H
#define DININGPHILOSOPHER_SEMAPHOR_H

#include <mutex>
#include <condition_variable>

class Semaphor {
public:
    Semaphor(size_t);
    void acquire();
    void release();
private:
    std::mutex mutex;
    std::condition_variable conditionVariable;
    size_t count;
};


#endif //DININGPHILOSOPHER_SEMAPHOR_H
