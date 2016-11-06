//
// Created by raeste on 05.11.16.
//

#ifndef DININGPHILOSOPHER_SEMARUNNER_H
#define DININGPHILOSOPHER_SEMARUNNER_H


#include <cstddef>

void SemaDinning(const size_t philosophersCount);
void LRDinning(const size_t philosophersCount);
void LLRDinning(const size_t philosophersCount);
void CoordinateDinning(const size_t philosophersCount);
void WaitReleaseDinning(const size_t philosophersCount);
void RandomWaitReleaseDinning(const size_t philosophersCount);

#endif //DININGPHILOSOPHER_SEMARUNNER_H
