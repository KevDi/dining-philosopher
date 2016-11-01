cmake_minimum_required(VERSION 3.5)
project(DiningPhilosopher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCES src/main.cpp  src/philosoph.cpp  src/Runnable.cpp src/Fork.cpp   src/SemaPhilosoph.cpp  src/Semaphor.cpp)

include_directories(include)

add_executable(DiningPhilosopher ${SOURCES})
target_link_libraries(DiningPhilosopher pthread)