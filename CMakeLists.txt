cmake_minimum_required(VERSION 3.5)
project(sinc LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(libconfig libconfig)
find_package(spdlog REQUIRED)
find_package(Catch2 REQUIRED)

add_definitions(-DSPDLOG_FMT_EXTERNAL)

add_subdirectory(src)

add_executable(runtest tests/main.cpp tests/ConfigurationTest.cpp src/Configuration.cpp)
target_link_libraries(runtest Catch2::Catch2 fmt::fmt config spdlog::spdlog)

#include(CTest)
#include(Catch)
#catch_discover_tests(test)
