cmake_minimum_required(VERSION 3.17)
project(LABA_4_1 C)
set(CMAKE_C_STANDARD 99)
add_executable(LABA_4_1 main.c)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(LABA_4_1 PRIVATE Threads::Threads)

