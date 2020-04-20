#ifndef CONFIGURATION_HPP__
#define CONFIGURATION_HPP__

#define SINC_CONFIG_ERROR_READING_ENTRY -2
#define SINC_CONFIG_ERROR_READING_FILE -1
#define SINC_CONFIG_ERROR_SUCCESS 0
#define DEFAULT_CONFIG_PATH_SYSTEM "/etc/sinc.conf"

namespace SincBinary {

    class Config {

    public:
        /**
         * Whether the output should be verbose
         */
        int verbose = 0;

        /**
         * Whether the output should be colored
         */
        int coloredOutput = 0;

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
         * @param path The path to the configuration
         *
         */
        Config(const char* path);

    private:
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
    };
}

#endif
