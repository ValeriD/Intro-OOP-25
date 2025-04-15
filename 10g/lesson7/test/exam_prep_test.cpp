#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch2.hpp"
#include "../exam_prep.cpp"

TEST_CASE("Device constructor", "[Device]")
{
    REQUIRE(Device::getCounter() == 0);

    SECTION("Valid construction")
    {
        Device d(8, 6.5, 999.99, "Apple", "ABC123");
        REQUIRE(Device::getCounter() == 1);
        REQUIRE(d.getMemorySize() == 8);
        REQUIRE(d.getScreenSize() == 6.5);
        REQUIRE(d.getPrice() == 999.99);
        REQUIRE(strcmp(d.getBrand(), "Apple") == 0);
        REQUIRE(strcmp(d.getConstantSerial(), "ABC123") == 0);
    }

    SECTION("Zero values")
    {
        REQUIRE_THROWS_AS(Device(0, 6.5, 999.99, "Apple", "ABC123"), invalid_argument);
        REQUIRE_THROWS_AS(Device(8, 0, 999.99, "Apple", "ABC123"), invalid_argument);
        REQUIRE_THROWS_AS(Device(8, 6.5, 0, "Apple", "ABC123"), invalid_argument);
    }

    SECTION("Negative values")
    {
        REQUIRE_THROWS_AS(Device(-8, 6.5, 999.99, "Apple", "ABC123"), invalid_argument);
        REQUIRE_THROWS_AS(Device(8, -6.5, 999.99, "Apple", "ABC123"), invalid_argument);
        REQUIRE_THROWS_AS(Device(8, 6.5, -999.99, "Apple", "ABC123"), invalid_argument);
    }

    SECTION("Empty strings")
    {
        REQUIRE_THROWS_AS(Device(8, 6.5, 999.99, "", "ABC123"), invalid_argument);
        REQUIRE_THROWS_AS(Device(8, 6.5, 999.99, "Apple", ""), invalid_argument);
    }

    SECTION("Null pointers")
    {
        REQUIRE_THROWS_AS(Device(8, 6.5, 999.99, nullptr, "ABC123"), invalid_argument);
        REQUIRE_THROWS_AS(Device(8, 6.5, 999.99, "Apple", nullptr), invalid_argument);
    }
}

TEST_CASE("Device copy constructor", "[Device]")
{
    Device original(8, 6.5, 999.99, "Apple", "ABC123");

    SECTION("Basic copy")
    {
        Device copy(original);
        REQUIRE(Device::getCounter() == 2);
        REQUIRE(copy.getMemorySize() == original.getMemorySize());
        REQUIRE(copy.getScreenSize() == original.getScreenSize());
        REQUIRE(copy.getPrice() == original.getPrice());
    }

    SECTION("Deep copy verification")
    {
        Device copy(original);
        REQUIRE(copy.getBrand() != original.getBrand());
        REQUIRE(strcmp(copy.getBrand(), original.getBrand()) == 0);

        copy.setBrand("Samsung");
        REQUIRE(strcmp(original.getBrand(), "Apple") == 0);
        REQUIRE(strcmp(copy.getBrand(), "Samsung") == 0);
    }
}

TEST_CASE("Device assignment operator", "[Device]")
{
    Device original(8, 6.5, 999.99, "Apple", "ABC123");

    SECTION("Self assignment")
    {
        original = original;
        REQUIRE(strcmp(original.getBrand(), "Apple") == 0);
    }

    SECTION("Chain assignment")
    {
        Device d2(16, 5.5, 799.99, "Samsung", "XYZ789");
        Device d3(32, 7.0, 1299.99, "Google", "DEF456");

        d3 = d2 = original;
        REQUIRE(strcmp(d2.getBrand(), "Apple") == 0);
        REQUIRE(strcmp(d3.getBrand(), "Apple") == 0);
    }

    SECTION("Deep copy on assignment")
    {
        Device other(16, 5.5, 799.99, "Samsung", "XYZ789");
        other = original;
        other.setBrand("Google");
        REQUIRE(strcmp(original.getBrand(), "Apple") == 0);
        REQUIRE(strcmp(other.getBrand(), "Google") == 0);
    }
}

TEST_CASE("Device counter behavior", "[Device]")
{
    SECTION("Multiple objects")
    {
        Device d1(8, 6.5, 999.99, "Apple", "ABC123");
        REQUIRE(Device::getCounter() == 1);

        {
            Device d2(16, 5.5, 799.99, "Samsung", "XYZ789");
            REQUIRE(Device::getCounter() == 2);
        }
        REQUIRE(Device::getCounter() == 1);
    }

    SECTION("Copy construction effect")
    {
        Device d1(8, 6.5, 999.99, "Apple", "ABC123");
        Device d2(d1);
        REQUIRE(Device::getCounter() == 2);
    }

    SECTION("Exception effect")
    {
        try
        {
            Device d(0, 6.5, 999.99, "Apple", "ABC123");
        }
        catch (const invalid_argument &)
        {
            REQUIRE(Device::getCounter() == 0);
        }
    }
}

TEST_CASE("Device isWorthBuying", "[Device]")
{
    SECTION("Worth buying")
    {
        Device d(32, 6.5, 1000, "Apple", "ABC123");
        REQUIRE(d.isWorthBuying() == true);
    }

    SECTION("Not worth buying")
    {
        Device d(8, 5.5, 2000, "Apple", "ABC123");
        REQUIRE(d.isWorthBuying() == false);
    }

    SECTION("Edge case - exactly 0.1")
    {
        Device d(10, 2, 200, "Test", "TEST123");
        REQUIRE(d.isWorthBuying() == false);
    }
}

TEST_CASE("Phone constructor", "[Phone]")
{
    SECTION("Valid construction")
    {
        Phone p(8, 6.5, 999.99, "Apple", "ABC123", 48);
        REQUIRE(p.getCameraParameters() == 48);
        REQUIRE(Device::getCounter() == 1);
    }

    SECTION("Invalid camera parameters")
    {
        REQUIRE_THROWS_AS(Phone(8, 6.5, 999.99, "Apple", "ABC123", 0), invalid_argument);
        REQUIRE_THROWS_AS(Phone(8, 6.5, 999.99, "Apple", "ABC123", -48), invalid_argument);
    }

    SECTION("Device parameter validation")
    {
        REQUIRE_THROWS_AS(Phone(0, 6.5, 999.99, "Apple", "ABC123", 48), invalid_argument);
        REQUIRE_THROWS_AS(Phone(8, 6.5, 999.99, "", "ABC123", 48), invalid_argument);
    }
}

TEST_CASE("Phone copy constructor", "[Phone]")
{
    Phone original(8, 6.5, 999.99, "Apple", "ABC123", 48);

    SECTION("Basic copy")
    {
        Phone copy(original);
        REQUIRE(copy.getCameraParameters() == original.getCameraParameters());
        REQUIRE(Device::getCounter() == 2);
    }

    SECTION("Deep copy verification")
    {
        Phone copy(original);
        copy.setCameraParameters(64);
        REQUIRE(original.getCameraParameters() == 48);
        REQUIRE(copy.getCameraParameters() == 64);
    }
}

TEST_CASE("Phone assignment operator", "[Phone]")
{
    Phone original(8, 6.5, 999.99, "Apple", "ABC123", 48);

    SECTION("Self assignment")
    {
        original = original;
        REQUIRE(original.getCameraParameters() == 48);
    }

    SECTION("Regular assignment")
    {
        Phone other(16, 5.5, 799.99, "Samsung", "XYZ789", 64);
        other = original;
        REQUIRE(other.getCameraParameters() == 48);
    }
}

TEST_CASE("Phone isWorthBuying", "[Phone]")
{
    SECTION("Worth buying")
    {
        Phone p(32, 6.5, 1000, "Apple", "ABC123", 48);
        REQUIRE(p.isWorthBuying() == true);
    }

    SECTION("Not worth buying")
    {
        Phone p(8, 5.5, 2000, "Apple", "ABC123", 12);
        REQUIRE(p.isWorthBuying() == false);
    }

    SECTION("Edge case - exactly 0.1")
    {
        Phone p(10, 1, 200, "Test", "TEST123", 1);
        REQUIRE(p.isWorthBuying() == false);
    }
}