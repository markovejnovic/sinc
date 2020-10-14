#pragma once

/**
 * SInstance represents a sinc instance.
 *
 * Each SInstance represents a sinc instance. This instance exposes methods for
 * sending a package, fetching state.
 */
class SInstance {
    public:
        virtual void sendPackage() = null;
        virtual void fetchState() = null;
        virtual void compareState(SInstance*) = null;
}

/**
 * LInstance represents the local sinc instance. This local sinc instance
 * should only exist once, and is therefore a singleton
 */
class LInstance : SInstance {
    public:
        static LInstance& getInstance() {
            static LInstance instance;
            
            return instance;
        }
        LInstance(LInstance const&) = delete;
        void operator=(LInstance const&) = delete;

        void sendPackage();
        void fetchState();
        void compareState(RInstance*);
}

/**
 * RInstance represents a remote sinc instance.
 */
class RInstance : SInstance {
    public:
        void sendPackage();
        void fetchState();
        void compareState(LInstance*);
}
