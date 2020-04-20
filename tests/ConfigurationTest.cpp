#include <catch2/catch.hpp>
#include <cstdlib>
#include <fmt/format.h>

#include "../src/Configuration.hpp"

using Catch::Matchers::Equals;
using namespace SincBinary;

TEST_CASE("The constructor correctly reads a test file defined in "
          "/home/test/.config/sinc.conf") {
    SincBinary::Config *testConfig = new
        SincBinary::Config("/home/test/.config/sinc.conf");

    REQUIRE(testConfig->verbose == 1);
    REQUIRE(testConfig->coloredOutput == 1);

    delete testConfig;
}
