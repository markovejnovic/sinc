#pragma once

#include <string>

#include "ISerializable.hpp"

/**
 * A PackageTypeAtom is the basis for forming a PackageType.
 */
class PackageTypeAtom : ISerializable {
    public:
        /**
         * Constructs the PackageTypeAtom from a simple string
         */
        PackageTypeAtom(const std::string&);

        /**
         * Serializes the PackageTypeAtom.
         */
        const char* serialize() const;

        /**
         * Two atoms are identical if their names are the same
         */
        bool operator==(const PackageTypeAtom&) const;

        /**
         * Returns the atomic name
         */
        const std::string getName() const;

        /**
         * Returns the next PackageTypeAtom, null if nonexistent
         */
        PackageTypeAtom* getNext() const;

        /**
         * Sets the next PackageTypeAtom
         */
        void setNext(PackageTypeAtom*);

    private:
        std::string name;
        PackageTypeAtom* next = nullptr;
};
