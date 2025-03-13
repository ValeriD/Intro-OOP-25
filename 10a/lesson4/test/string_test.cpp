#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../string_homework2.cpp"

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

TEST_CASE("Insert method functionality", "[String]")
{
    SECTION("Insert at beginning")
    {
        String str("hello");
        str.insert(0, 'H');
        REQUIRE(strcmp(str.toCString(), "Hhello") == 0);
    }

    SECTION("Insert in middle")
    {
        String str("hello");
        str.insert(2, '-');
        REQUIRE(strcmp(str.toCString(), "he-llo") == 0);
    }

    SECTION("Insert at end")
    {
        String str("hello");
        str.insert(5, '!');
        REQUIRE(strcmp(str.toCString(), "hello!") == 0);
    }

    SECTION("Insert at invalid position")
    {
        String str("hello");
        str.insert(10, 'x');
        REQUIRE(strcmp(str.toCString(), "hello") == 0);
    }
}

TEST_CASE("Replace method functionality", "[String]")
{
    SECTION("Replace first character")
    {
        String str("hello");
        str.replace(0, 'H');
        REQUIRE(strcmp(str.toCString(), "Hello") == 0);
    }

    SECTION("Replace middle character")
    {
        String str("hello");
        str.replace(2, 'L');
        REQUIRE(strcmp(str.toCString(), "heLlo") == 0);
    }

    SECTION("Replace last character")
    {
        String str("hello");
        str.replace(4, 'O');
        REQUIRE(strcmp(str.toCString(), "hellO") == 0);
    }

    SECTION("Replace at invalid position")
    {
        String str("hello");
        str.replace(10, 'x');
        REQUIRE(strcmp(str.toCString(), "hello") == 0);
    }
}

TEST_CASE("FindFirstOf method functionality", "[String]")
{
    SECTION("Find character at beginning")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('h') == 0);
    }

    SECTION("Find character in middle")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('l') == 2);
    }

    SECTION("Find character at end")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('o') == 4);
    }

    SECTION("Find non-existent character")
    {
        String str("hello");
        REQUIRE(str.findFirstOf('x') == -1);
    }

    SECTION("Find in empty string")
    {
        String str;
        REQUIRE(str.findFirstOf('a') == -1);
    }
}