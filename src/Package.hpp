/**
 * A sinc Package is an object which contains the data type and the data
 * itself.
 */
class Package : ISerializable {
    public:
        /**
         * Returns the type of package
         */
        PackageType getType();

        /**
         * Returns the data of the package
         */
        PackageData getData();

        const char* serialize();

    private:
        const char* PackageType type;
        PackageData* data;
};
