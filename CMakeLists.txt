cmake_minimum_required(VERSION 3.10)
project(multithreading)
add_executable(executable main.c thread.c glthread.c)
target_link_libraries(executable pthread)