cmake_minimum_required(VERSION 3.5)
project(sinc LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

find_library(libconfig libconfig)
find_package(spdlog REQUIRED)
find_package(Catch2 REQUIRED)
find_package(Boost 1.40.0 REQUIRED system)

add_definitions(-DSPDLOG_FMT_EXTERNAL)

add_subdirectory(src)

add_executable(runtest tests/main.cpp tests/ConfigurationTest.cpp src/Configuration.cpp)
target_link_libraries(runtest Catch2::Catch2 fmt::fmt config spdlog::spdlog)

#include(CTest)
#include(Catch)
#catch_discover_tests(test)
