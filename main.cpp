#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <pthread.h>
#include <semaphore.h>

#include "Timer.hpp"
#include <Semaphore.hpp>

//    std::thread th1(work, std::ref(n));
//    th1.join();
void work(int &n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    n *= n;
    std::cout << "ID flow = " << std::this_thread::get_id() << "\twork" <<  std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

//    int sumDig;
//    std::thread th2([&]() { sumDig = sum(n, n); });
//    th2.join();
int sum(int a, int b) {
    std::cout << "ID flow = " << std::this_thread::get_id() << "\tsum" <<  std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return a + b;
}

int lastColor = 0;
std::string colors[]{
"\u001B[0m",
"\u001B[30m",
"\u001B[31m",
"\u001B[32m",
"\u001B[33m",
"\u001B[34m",
"\u001B[35m",
"\u001B[36m",
"\u001B[37m",
"\u001B[38m",
"\u001B[39m"
};

Semaphore semaphore;

void print(char ch) {
//    semaphore.wait();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (lastColor == 11) lastColor = 0;
            std::cout << colors[lastColor] << "Hello world" << std::endl;
            lastColor++;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
//    semaphore.post();
}

int main() {
    Timer timer;
    semaphore.init(12);
    std::vector<std::thread> threads;
    threads.emplace_back(print, 'a');
    threads.emplace_back(print, 'b');

    for (int i = 0; i < threads.size(); ++i) {
        threads[i].join();
    }
}