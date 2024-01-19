#pragma once

#include <thread>

typedef int32_t (*ThreadFn)(class Thread *_self, void *_userData);

class Thread {
public:
    bool init(ThreadFn _fn, void *_userData = NULL, uint32_t _stackSize = 0, const char *_name = NULL);
private:
    std::thread thread;
};
