#include <catch2/catch.hpp>
#include <cstdlib>
#include <fmt/format.h>
#include "../src/Configuration.hpp"

using namespace SincBinary::Config;
using Catch::Matchers::Equals;

TEST_CASE("getUserConfPath(char* userPath) returns the path to the current " 
          "environment variable appended by .config/sinc.conf") {
    const char* bakEnv = getenv("HOME");
    putenv((char *)"HOME=/home/test");

    char userPath[1024];
    getUserConfPath(userPath);

    REQUIRE_THAT(userPath, Equals("/home/test/.config/sinc.conf"));

    putenv((char *)fmt::format("HOME={}", bakEnv).c_str());
}

TEST_CASE("readConfig(const char* path) successfully reads a correct config "
          "file.") {
    // TODO: Write test case
}
