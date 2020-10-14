#include "PackageTypeAtom.hpp"

PackageTypeAtom::PackageTypeAtom(const std::string& atom) {
    this->name = atom;
}

const std::string PackageTypeAtom::getName() const {
    return name;
}

PackageTypeAtom* PackageTypeAtom::getNext() const {
    return next;
}

void PackageTypeAtom::setNext(PackageTypeAtom* newPTA) {
    next = newPTA;
}

bool PackageTypeAtom::operator==(const PackageTypeAtom& other) const {
    return getName() == other.getName();
}

const char* PackageTypeAtom::serialize() const {
    return getName().c_str();
}
