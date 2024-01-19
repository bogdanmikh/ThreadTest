#pragma once

#include <pthread.h>
#include <semaphore.h>
#include <cstdint>

class Semaphore {
public:
    void init(uint32_t size);
    int wait();
    void post();
    ~Semaphore();
private:
    sem_t *semaphore;
};
