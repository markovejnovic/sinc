#include <cstdio>

#include "Configuration.hpp"

using namespace SincBinary;

int main(int argc, char **argv) {
    char userPath[1024];
    Config::getUserConfPath(userPath);

    printf("%s", userPath);
    return 0;
}
