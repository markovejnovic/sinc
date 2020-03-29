#pragma once

#define SINC_CONFIG_ERROR_READING_ENTRY -2
#define SINC_CONFIG_ERROR_READING_FILE -1
#define SINC_CONFIG_ERROR_SUCCESS 0

namespace SincBinary
{
    namespace Config
    {
        const static char* DEFAULT_PATH_SYSTEM = "/etc/sinc.conf";

        /**
         * Whether the output should be verbose
         */
        static int verbose = 0;

        /**
         * Whether the output should be colored
         */
        static int coloredOutput = 0;

        /**
         * Initializes the configuration
         *
         * This reads from the configuration path given in path. If path is
         * null or not passed, then the function reads from the
         * DEFAULT_PATH_USER location. Furthermore, if this file does not
         * exist, the function attempts to read from DEFAULT_PATH_SYSTEM.
         * If DEFAULT_PATH_SYSTEM does not exist, the configuration values
         * remain as default. The function attempts to write those default
         * values to DEFAULT_PATH_USER.
         *
         * @param path 
         *
         */
        void init(const char* path);

        /**
         * Reads the given configuration file and sets the variables
         * appropriately.
         *
         * @param path The path to the configuration file
         *
         * @returns Error The appropriate error code
         */
        int readConfig(const char* path);

        /**
         * Returns the user configuration path
         *
         * This should be ~/.config/sinc.conf
         *
         * @param userPath The string containing the path to the user folder
         */
        void getUserConfPath(char* userPath);
    }
}
