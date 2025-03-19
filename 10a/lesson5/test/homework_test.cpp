#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../homework.cpp"

TEST_CASE("Vector Constructor", "[vector]")
{
    SECTION("Valid construction")
    {
        REQUIRE_NOTHROW(Vector(1, 5));
        Vector v(1, 5);
        REQUIRE(v.getCapacity() == 5);
        REQUIRE(v.getId() == 1);
        REQUIRE(v.getSize() == 0);
    }

    SECTION("Invalid capacity")
    {
        REQUIRE_THROWS_AS(Vector(1, 0), invalid_argument);
        REQUIRE_THROWS_AS(Vector(1, -1), invalid_argument);
    }

    SECTION("Invalid id")
    {
        REQUIRE_THROWS_AS(Vector(0, 5), invalid_argument);
        REQUIRE_THROWS_AS(Vector(-1, 5), invalid_argument);
    }
}

TEST_CASE("Vector Basic Getters", "[vector]")
{
    Vector v(1, 5);

    SECTION("Initial state")
    {
        REQUIRE(v.getSize() == 0);
        REQUIRE(v.getCapacity() == 5);
        REQUIRE(v.getId() == 1);
    }
}

TEST_CASE("Vector PushBack", "[vector]")
{
    Vector v(1, 2);

    SECTION("Basic push")
    {
        v.pushBack(1);
        REQUIRE(v.getSize() == 1);
        REQUIRE(v.at(0) == 1);
    }

    SECTION("Push with resize")
    {
        v.pushBack(1);
        v.pushBack(2);
        v.pushBack(3); // This should trigger resize
        REQUIRE(v.getSize() == 3);
        REQUIRE(v.getCapacity() == 4);
        REQUIRE(v.at(2) == 3);
    }
}

TEST_CASE("Vector At", "[vector]")
{
    Vector v(1, 5);
    v.pushBack(10);
    v.pushBack(20);

    SECTION("Valid access")
    {
        REQUIRE(v.at(0) == 10);
        REQUIRE(v.at(1) == 20);
    }

    SECTION("Invalid access")
    {
        REQUIRE_THROWS_AS(v.at(-1), out_of_range);
        REQUIRE_THROWS_AS(v.at(2), out_of_range);
    }
}

TEST_CASE("Vector Insert", "[vector]")
{
    Vector v(1, 5);
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    SECTION("Insert at beginning")
    {
        v.insert(0, 10);
        REQUIRE(v.at(0) == 10);
        REQUIRE(v.at(1) == 1);
    }

    SECTION("Insert at middle")
    {
        v.insert(1, 10);
        REQUIRE(v.at(0) == 1);
        REQUIRE(v.at(1) == 10);
        REQUIRE(v.at(2) == 2);
    }

    SECTION("Insert at end")
    {
        v.insert(3, 10);
        REQUIRE(v.at(3) == 10);
    }

    SECTION("Invalid insert")
    {
        REQUIRE_THROWS_AS(v.insert(-1, 10), out_of_range);
        REQUIRE_THROWS_AS(v.insert(4, 10), out_of_range);
    }
}

TEST_CASE("Vector Remove", "[vector]")
{
    Vector v(1, 5);
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    SECTION("Remove from beginning")
    {
        v.remove(0);
        REQUIRE(v.getSize() == 2);
        REQUIRE(v.at(0) == 2);
    }

    SECTION("Remove from middle")
    {
        v.remove(1);
        REQUIRE(v.getSize() == 2);
        REQUIRE(v.at(0) == 1);
        REQUIRE(v.at(1) == 3);
    }

    SECTION("Remove from end")
    {
        v.remove(2);
        REQUIRE(v.getSize() == 2);
        REQUIRE(v.at(1) == 2);
    }

    SECTION("Invalid remove")
    {
        REQUIRE_THROWS_AS(v.remove(-1), out_of_range);
        REQUIRE_THROWS_AS(v.remove(3), out_of_range);
    }
}

TEST_CASE("Vector Pop", "[vector]")
{
    Vector v(1, 5);

    SECTION("Pop from non-empty vector")
    {
        v.pushBack(1);
        v.pushBack(2);
        v.pop();
        REQUIRE(v.getSize() == 1);
    }

    SECTION("Pop from empty vector")
    {
        REQUIRE_THROWS_AS(v.pop(), out_of_range);
    }
}