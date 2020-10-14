#pragma once

/**
 * Represents a serializable object.
 */
class ISerializable {
    public:
        /**
         * Defines serialization
         */
        virtual const char* serialize() const = 0;
};
