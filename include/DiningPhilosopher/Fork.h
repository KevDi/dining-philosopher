//
// Created by raeste on 30.10.16.
//

#ifndef DININGPHILOSOPHER_FORK_H
#define DININGPHILOSOPHER_FORK_H

#include <mutex>

class Fork {
public:
    Fork();
    std::mutex mutex;
};


#endif //DININGPHILOSOPHER_FORK_H
