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

TEST_CASE("append() Method", "[string]")
{
    SECTION("Append to empty string")
    {
        String s;
        s.append('a');
        REQUIRE(s.length() == 1);
        REQUIRE(strcmp(s.toCString(), "a") == 0);
    }

    SECTION("Append to non-empty string")
    {
        String s("hello");
        s.append('!');
        REQUIRE(s.length() == 6);
        REQUIRE(strcmp(s.toCString(), "hello!") == 0);
    }

    SECTION("Append null character")
    {
        String s("test");
        s.append('\0');
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "test") == 0);
    }
}

TEST_CASE("concat() Method", "[string]")
{
    SECTION("Concat to empty string")
    {
        String s;
        s.concat("hello");
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "hello") == 0);
    }

    SECTION("Concat empty string")
    {
        String s("hello");
        s.concat("");
        REQUIRE(s.length() == 5);
        REQUIRE(strcmp(s.toCString(), "hello") == 0);
    }

    SECTION("Concat two non-empty strings")
    {
        String s("hello");
        s.concat(" world");
        REQUIRE(s.length() == 11);
        REQUIRE(strcmp(s.toCString(), "hello world") == 0);
    }
}

TEST_CASE("compare() Method", "[string]")
{
    SECTION("Equal strings")
    {
        String s1("hello");
        String s2("hello");
        REQUIRE(s1.compare(s2) == 0);
    }

    SECTION("Empty strings")
    {
        String s1;
        String s2;
        REQUIRE(s1.compare(s2) == 0);
    }

    SECTION("Different length strings")
    {
        String s1("hello");
        String s2("hello world");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }

    SECTION("Different content, same length")
    {
        String s1("hello");
        String s2("world");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }

    SECTION("Prefix strings")
    {
        String s1("hell");
        String s2("hello");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }

    SECTION("Different characters")
    {
        String s1("abc");
        String s2("abd");
        REQUIRE(s1.compare(s2) == -1);
        REQUIRE(s2.compare(s1) == 1);
    }
}