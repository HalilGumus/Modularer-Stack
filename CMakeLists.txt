cmake_minimum_required(VERSION 3.8)
project(ModularStack)

set(CMAKE_CXX_STANDARD 14)

add_executable(ModularStack-Test test.c mystack.c)
add_executable(ModularStack main.c mystack.c)
