#pragma once

#include <unordered_map>

#include "PackageType.hpp"
#include "Module.hpp"

/**
 * The ModuleManager object is an object which manages the behavior of various
 * modules.
 *
 * Modules are stored in a map where the key is the PackageType of the module,
 * while the value is the module itself.
 */
class ModuleManager {
    public:
        /**
         * Attempts to manage a moduel
         */
        void addModule(Module*);

        /**
         * Returns true if the given PackageType is managed, false otherwise.
         */
        bool checkIfTypeManaged(PackageType);

        /**
         * Returns the appropriate module given the package type. null if not
         * found.
         */
        Module* getModuleForPackageType(PackageType);

    private:
        std::unordered_map<PackageType, Module*> modules;
};
