#include <libconfig.h>
#include <spdlog/spdlog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <limits.h>

#include "Configuration.hpp"

namespace SincBinary::Config {
    void init(const char* path) {
        if (path == NULL || readConfig(path) == SINC_CONFIG_ERROR_READING_FILE) {
            // TODO: Now, technically, PATH_MAX isn't the longest possible path
            // but in this purpose it should work well enough most of the time.
            // See https://eklitzke.org/path-max-is-tricky for more info
            char userPath[PATH_MAX];
            getUserConfPath(userPath);
            if (readConfig(userPath) == SINC_CONFIG_ERROR_READING_FILE) {
                if (readConfig(DEFAULT_PATH_SYSTEM) ==
                    SINC_CONFIG_ERROR_READING_FILE) {
                    // TODO: Write to DEFAULT_PATH_USER
                }
            }
        }

    }

    void getUserConfPath(char *userPath) {
        const char* homeDir = getenv("HOME");
        if (homeDir == NULL) {
            homeDir = getpwuid(getuid())->pw_dir;
        }

        const char* configPath = "/.config/sinc.conf";

        // The fact that this is not freed is fine, since all SincBinary::Config
        // variables are permanently existent in memory anyways
        strcpy(userPath, homeDir);
        strcat(userPath, configPath);
    }

    int readConfig(const char* path) {
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

        config_lookup_bool(cf, "verbose", &verbose);
        config_lookup_bool(cf, "coloredOutput", &coloredOutput);

        config_destroy(cf);
        return SINC_CONFIG_ERROR_SUCCESS;
    }
}
