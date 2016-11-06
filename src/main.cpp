#include <iostream>
#include <DiningPhilosopher/Globals.h>
#include "DiningPhilosopher/Runner.h"


int main() {
    SemaDinning(philosophers);
    LRDinning(philosophers);
    LLRDinning(philosophers);
    CoordinateDinning(philosophers);
    WaitReleaseDinning(philosophers);
    RandomWaitReleaseDinning(philosophers);
    return 0;
}