cmake_minimum_required(VERSION 3.17)
project(Threads)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

add_executable(Threads
        main.cpp
        Timer.hpp
        src/Semaphore.hpp
        src/Semaphore.cpp
        src/Thread.cpp
)

target_link_libraries(Threads Threads::Threads)
target_include_directories(Threads PRIVATE src)
