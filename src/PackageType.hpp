#pragma once

#include <string>

#include "ISerializable.hpp"
#include "PackageTypeAtom.hpp"

/**
 * A PackageType represents a specific type of package. Each module announces
 * the package it processes through the package type.
 *
 * Here follows a lengthy design discussion on the operation of PackageType.
 * Given that folders have a tree-like structure:
 * - documents/
 *   - text/
 *     - foo.txt
 *     - bar.text
 *   - photos/
 *     - img.jpg
 *     - img.bmp
 *   - doc.odt
 *
 * It is reasonable to conclude that data can come in similar forms. A dummy
 * example could be that you could have data of
 * documents/text/txt,
 * documents/text/text,
 * documents/photos/jpg,
 * documents/photos/bmp,
 * documents/typing/odt
 *
 * Now, it's clear that .txt data and .text data might want to be processed by
 * the same module. Then, if a module registers itself as a doc/text/ module,
 * then it would make sense for the module to be handling those files.
 *
 * If another module then comes around and specifically announces itself as a
 * doc/text/txt module, then .txt files ought to be handled by the latter
 * module, while the prior module would be still able to handle .text files.
 * 
 * The equivalent of this can be thought in data itself. For example, you could
 * have contact/google, contact/outlook (yikes). If there is a module which can
 * handle both, then it would register itself as a contact/ module.
 *
 * Whatsmore, someone who registers the type of / would be able to intercept
 * all data which was not intercepted by another module. This must have some
 * use.
 *
 * [ISSUE]: The biggest issue here is that module authors will inevitably, by
 * accident, register their modules for stuff their module cannot process. This
 * type of tree-typing is still nice, and authors of modules should register
 * their modules as tightly as possible.
 *
 * TL;DR Types follow tree-like structures.
 *
 * PackageTypes are comprized of PackageTypeAtoms.
 */
class PackageType : ISerializable {
    public:
        /**
         * Serializes the PackageType.
         */
        const char* serialize() const;

        /**
         * Converts the appropriate string into the package type. Strings must
         * be ASCII.
         *
         * PackageType strings take the form of '/type/subtype/subsubtype...'.
         */
        static PackageType fromString(std::string);

    private:
        PackageTypeAtom* head;
};
