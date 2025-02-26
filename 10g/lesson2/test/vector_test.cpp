#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../vector.cpp"

TEST_CASE("Vector initialization", "[vector]")
{
    Vector *v = initVector();

    SECTION("New vector should have correct initial values")
    {
        REQUIRE(v != nullptr);
        REQUIRE(v->size == 0);
        REQUIRE(v->capacity == 2);
        REQUIRE(v->data != nullptr);
    }
}

TEST_CASE("Vector push_back operations", "[vector]")
{
    Vector *v = initVector();

    SECTION("Single push_back")
    {
        pushBack(v, 42);
        REQUIRE(v->size == 1);
        REQUIRE(v->data[0] == 42);
    }

    SECTION("Multiple push_backs without resize")
    {
        pushBack(v, 10);
        pushBack(v, 20);
        REQUIRE(v->size == 2);
        REQUIRE(v->data[0] == 10);
        REQUIRE(v->data[1] == 20);
        REQUIRE(v->capacity == 2);
    }

    SECTION("Push_back triggering resize")
    {
        pushBack(v, 1);
        pushBack(v, 2);
        pushBack(v, 3);
        REQUIRE(v->size == 3);
        REQUIRE(v->capacity == 4);
        REQUIRE(v->data[0] == 1);
        REQUIRE(v->data[1] == 2);
        REQUIRE(v->data[2] == 3);
    }

    //
}

TEST_CASE("Vector resize behavior", "[vector]")
{
    Vector *v = initVector();

    SECTION("Resize doubles capacity and preserves data")
    {
        // Fill initial capacity
        pushBack(v, 100);
        pushBack(v, 200);

        size_t oldCapacity = v->capacity;

        // Trigger resize
        pushBack(v, 300);

        REQUIRE(v->capacity == oldCapacity * 2);
        REQUIRE(v->data[0] == 100);
        REQUIRE(v->data[1] == 200);
        REQUIRE(v->data[2] == 300);
    }

    //
}

TEST_CASE("Vector print output", "[vector]")
{
    Vector *v = initVector();

    SECTION("Print empty vector")
    {
        // Redirect cout to our stringstream
        std::stringstream output;
        std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

        print(v);

        // Restore cout
        std::cout.rdbuf(oldCout);

        REQUIRE(output.str().find("Vector's size: 0") != std::string::npos);
        REQUIRE(output.str().find("Vector's capacity: 2") != std::string::npos);
        REQUIRE(output.str().find("Vector's data: []") != std::string::npos);
    }

    SECTION("Print vector with elements")
    {
        pushBack(v, 1);
        pushBack(v, 2);

        std::stringstream output;
        std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

        print(v);

        std::cout.rdbuf(oldCout);

        REQUIRE(output.str().find("Vector's size: 2") != std::string::npos);
        REQUIRE(output.str().find("Vector's capacity: 2") != std::string::npos);
        REQUIRE(output.str().find("Vector's data: [1 2]") != std::string::npos);
    }

    //
}

TEST_CASE("Vector at() function", "[vector]")
{
    Vector *v = initVector();

    SECTION("Regular access")
    {
        pushBack(v, 10);
        pushBack(v, 20);
        REQUIRE(at(v, 0) == 10);
        REQUIRE(at(v, 1) == 20);
    }

    SECTION("Edge cases")
    {
        REQUIRE(at(v, -1) == ERROR);
        REQUIRE(at(v, 0) == ERROR); // Empty vector
        pushBack(v, 10);
        REQUIRE(at(v, 1) == ERROR); // Out of bounds
    }
}

TEST_CASE("Vector pop() function", "[vector]")
{
    Vector *v = initVector();

    SECTION("Regular pop")
    {
        pushBack(v, 10);
        pushBack(v, 20);
        REQUIRE(pop(v) == 20);
        REQUIRE(v->size == 1);
    }

    SECTION("Edge cases")
    {
        REQUIRE(pop(v) == ERROR); // Empty vector
    }
}