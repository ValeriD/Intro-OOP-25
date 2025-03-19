#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../string_homework.cpp"

TEST_CASE("Default Constructor", "[string]")
{
    String s;
    REQUIRE(s.length() == 0);
    REQUIRE(strcmp(s.toCString(), "") == 0);
}

TEST_CASE("C-string Constructor", "[string]")
{
    SECTION("Normal string")
    {
        String s("hello");
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "hello") == 0);
    }

    SECTION("Empty string")
    {
        String s("");
        REQUIRE(s.length() == 0);
        REQUIRE(strcmp(s.toCString(), "") == 0);
    }

    SECTION("Single character")
    {
        String s("a");
        REQUIRE(s.length() == 1);
        REQUIRE(strcmp(s.toCString(), "a") == 0);
    }
}

TEST_CASE("Copy constructor functionality", "[String]")
{
    SECTION("Copy empty string")
    {
        String empty;
        String copy(empty);
        REQUIRE(copy.length() == 0);
        REQUIRE(copy.toCString()[0] == '\0');
    }

    SECTION("Copy non-empty string")
    {
        String original("test");
        String copy(original);
        REQUIRE(copy.length() == 4);
        REQUIRE(strcmp(copy.toCString(), "test") == 0);
        REQUIRE(copy.toCString() != original.toCString()); // Different memory addresses
    }
}

TEST_CASE("Assignment operator functionality", "[String]")
{
    SECTION("Assign to empty string")
    {
        String source("hello");
        String dest;
        dest = source;
        REQUIRE(strcmp(dest.toCString(), "hello") == 0);
    }

    SECTION("Assign to non-empty string")
    {
        String source("world");
        String dest("hello");
        dest = source;
        REQUIRE(strcmp(dest.toCString(), "world") == 0);
    }

    SECTION("Self assignment")
    {
        String str("test");
        str = str;
        REQUIRE(strcmp(str.toCString(), "test") == 0);
    }
}