#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main(int argc, char* argv[]) {
    auto console = spdlog::stdout_color_mt("console");
    spdlog::set_default_logger(console);

    return Catch::Session().run(argc, argv);
}
