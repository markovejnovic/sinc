cmake_minimum_required(VERSION 3.1)

project(sinc LANGUAGES CXX VERSION 0.0.1)

find_library(libconfig libconfig)
find_package(spdlog REQUIRED)
find_package(Catch2 REQUIRED)

add_definitions(-DSPDLOG_FMT_EXTERNAL)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include_directories(src)

add_executable(sinc src/main.cpp src/Configuration.cpp)
target_link_libraries(sinc config++ spdlog::spdlog config)

add_executable(test tests/main.cpp tests/ConfigurationTest.cpp src/Configuration.cpp)
target_link_libraries(test Catch2::Catch2 fmt::fmt config spdlog::spdlog)

include(CTest)
include(Catch)
catch_discover_tests(tests)
