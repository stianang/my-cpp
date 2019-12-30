#include "../my_string.h"
#include "catch.hpp"

TEST_CASE("my::string::replace_s") 
{
    std::string input = "test name is";
    my::string::replace(input, "name", "Johnson");
    REQUIRE(input == "test Johnson is");
}

TEST_CASE("my::string::replace_c") 
{
    std::string input = "test";
    my::string::replace(input, 't', 'e');
    REQUIRE(input == "eese");
}

TEST_CASE("my::string::replaceRange") 
{
    std::string input = "test name is";
    my::string::replaceRange(input, 5, 9, "john");
    REQUIRE(input == "test john is");
}

TEST_CASE("my::string::insert") 
{
    std::string input = "test name";
    my::string::insert(input, 5, "first");
    REQUIRE(input == "test firstname");
}

TEST_CASE("my::string::split_join") 
{
    std::string input = "name:test:end:";
    auto list = my::string::split(input, ":");
    REQUIRE(list[0] == "name");
    REQUIRE(list[1] == "test");
    REQUIRE(list[2] == "end");
    REQUIRE(list[3] == "");
    REQUIRE(list.size() == 4);

    std::string joined = my::string::join(list, ":");
    REQUIRE(joined == input);
}

TEST_CASE("my::string::contains") 
{
    std::string input = "this is a long string";
    REQUIRE(my::string::contains(input, "is a"));
    REQUIRE(my::string::contains(input, " "));
    REQUIRE(my::string::contains(input, "th"));
    REQUIRE(!my::string::contains(input, "  "));
}

TEST_CASE("my::string::beginsWith") 
{
    std::string input = "this is a long string";
    REQUIRE(my::string::beginsWith(input, "this is"));
    REQUIRE(my::string::beginsWith(input, "t"));
    REQUIRE(my::string::beginsWith(input, "th"));
    REQUIRE(!my::string::beginsWith(input, " ing"));
}

TEST_CASE("my::string::endsWith") 
{
    std::string input = "this is a long string";
    REQUIRE(!my::string::endsWith(input, "thi"));
    REQUIRE(my::string::endsWith(input, " string"));
    REQUIRE(my::string::endsWith(input, "ng"));
    REQUIRE(!my::string::endsWith(input, "ing "));
}

TEST_CASE("my::string::trimEnd") 
{
    std::string input = "  test name  ";
    my::string::trimEnd(input);
    REQUIRE(input == "  test name");
}

TEST_CASE("my::string::trimStart") 
{
    std::string input = "  test name  ";
    my::string::trimStart(input);
    REQUIRE(input == "test name  ");
}

TEST_CASE("my::string::trim") 
{
    std::string input = "  test name  ";
    my::string::trim(input);
    REQUIRE(input == "test name");
}


TEST_CASE("my::string::toInt") 
{
    std::string s = "4.53";

    REQUIRE(my::string::toInt(s) == int(4));
    REQUIRE(my::string::toDouble(s) == double(4.53));
}

TEST_CASE("my::string::toDouble") 
{
    std::string s = "4.53";

    REQUIRE(my::string::toDouble(s) == double(4.53));
}

TEST_CASE("my::string::substring") 
{
    std::string s = "this is a test";
    REQUIRE(my::string::substring(s, 6) == "this i");

    REQUIRE(my::string::substring(s, 5, 7) == "is");
    REQUIRE(my::string::substring(s, 5, 88) == "is a test");
    REQUIRE(my::string::substring(s, 5, 3) == "");
}

TEST_CASE("my::string::findIndex") 
{
    std::string s = "this is a test";
    REQUIRE(my::string::findIndex(s, "is a") == 5);
}
