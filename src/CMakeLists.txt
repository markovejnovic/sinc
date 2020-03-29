add_executable(sinc main.cpp Configuration.cpp)
target_link_libraries(sinc config++ spdlog::spdlog config)
