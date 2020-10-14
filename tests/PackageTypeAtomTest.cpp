#include <catch2/catch.hpp>

#include "../src/PackageTypeAtom.hpp"

TEST_CASE("PackageTypeAtoms are equal if their name is equal") {
    PackageTypeAtom p1 = PackageTypeAtom("document");
    PackageTypeAtom p2 = PackageTypeAtom("document");

    REQUIRE(p1 == p2);
}

TEST_CASE("PackageTypeAtom.getName() works") {
    PackageTypeAtom p1 = PackageTypeAtom("name");

    REQUIRE("name" == p1.getName());
}

TEST_CASE("PackageTypeAtoms can have next atoms") {
    PackageTypeAtom* p1 = new PackageTypeAtom("document");

    REQUIRE(nullptr == p1->getNext());

    p1->setNext(new PackageTypeAtom("txt"));

    REQUIRE("txt" == p1->getNext()->getName());

    delete p1->getNext();
    delete p1;
}
