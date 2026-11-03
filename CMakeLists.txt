cmake_minimum_required(VERSION 3.10)
project(CoffeeMachines LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_executable(coffee_app src/main.cpp)
target_link_libraries(coffee_app PRIVATE coffee_lib)
