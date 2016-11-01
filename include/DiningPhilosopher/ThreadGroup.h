//
// Created by raeste on 30.10.16.
//

#ifndef DININGPHILOSOPHER_THREADGROUP_H
#define DININGPHILOSOPHER_THREADGROUP_H


#include <cstddef>
#include <functional>
#include <vector>
#include <thread>

class ThreadGroup {
public:
    ThreadGroup() = default;
    ThreadGroup(const ThreadGroup&) = delete;
    ~ThreadGroup() {
        for(const auto& pthread : pthreads) {
            delete pthread;
        }
    }

    ThreadGroup& operator=(const ThreadGroup&) = delete;

    template<typename  F>
    void add_thread(F& f) {
        pthreads.push_back(new std::thread(std::ref(f)));
    }

    void join_all() {
        for(const auto& pthread : pthreads) {
            pthread->join();
        }
    }

    std::size_t size() const {
        return pthreads.size();
    }

private:
    std::vector<std::thread*> pthreads;
};


#endif //DININGPHILOSOPHER_THREADGROUP_H
