#pragma once

#include <iostream>
#include <chrono>

class Timer {
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float result = duration.count();
        std::cout << "Time run program: " << result << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
};