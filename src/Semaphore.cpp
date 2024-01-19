#include "Semaphore.hpp"

Semaphore::~Semaphore() {
    sem_destroy(semaphore);
    delete semaphore;
}

void Semaphore::init(uint32_t size) {
    semaphore = new sem_t();
    sem_init(semaphore, 0, size);
}

int Semaphore::wait() {
    int result = sem_wait(semaphore);
    return result == 0;
}

void Semaphore::post() {
    int result = sem_post(semaphore);
}

