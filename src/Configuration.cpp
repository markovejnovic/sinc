#include <libconfig.h>
#include <spdlog/spdlog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <limits.h>
#include <cstdio>

#include "Configuration.hpp"

SincBinary::Config::Config(const char* path) {
    if (path == NULL || readConfig(path) == SINC_CONFIG_ERROR_READING_FILE) {
        // TODO: Now, technically, PATH_MAX isn't the longest possible path
        // but in this purpose it should work well enough most of the time.
        // See https://eklitzke.org/path-max-is-tricky for more info.
        char userPath[PATH_MAX];
        getUserConfPath(userPath);
        if (readConfig(userPath) == SINC_CONFIG_ERROR_READING_FILE) {
            if (readConfig(DEFAULT_CONFIG_PATH_SYSTEM) ==
                SINC_CONFIG_ERROR_READING_FILE) {
                // TODO: Write to DEFAULT_PATH_USER
            }
        }
    }
}

void SincBinary::Config::getUserConfPath(char *userPath) {
    const char* homeDir = getenv("HOME");
    if (homeDir == NULL) {
        homeDir = getpwuid(getuid())->pw_dir;
    }

    const char* configPath = "/.config/sinc.conf";

    strcpy(userPath, homeDir);
    strcat(userPath, configPath);
}

int SincBinary::Config::readConfig(const char* path) {
    if (path == NULL) {
        spdlog::warn("No path passed to readConfig(const char* path).");
        return SINC_CONFIG_ERROR_READING_FILE;
    }
    
    config_t cfg, *cf;
    const config_setting_t *retries;
    const char *base = NULL;

    cf = &cfg;
    config_init(cf);

    if (!config_read_file(cf, path)) {
        spdlog::error("Could not read file {} at line {}. Error: {}",
            config_error_file(cf),
            config_error_line(cf),
            config_error_text(cf));
        config_destroy(cf);
        return SINC_CONFIG_ERROR_READING_FILE;
    }

    int a;
    if (config_lookup_bool(cf, "verbose", &this->verbose) !=
            CONFIG_TRUE) {
        spdlog::error("Could not read `verbose` value in {}", path);
    }
    if (config_lookup_bool(cf, "coloredOutput", &this->coloredOutput) !=
            CONFIG_TRUE) {
        spdlog::error("Could not read `coloredOutput` value in {}", path);
    }

    config_destroy(cf);
    return SINC_CONFIG_ERROR_SUCCESS;
}
