#include "catch.hpp"
#include "../my_vector.h"

TEST_CASE("my::vector::contains")
{
    std::vector<int> list{1,5,2,7,4,333,65};
    REQUIRE(my::vector::contains(list, 65));
    REQUIRE(my::vector::contains(list, 7));
    REQUIRE(!my::vector::contains(list, 9));

    std::vector<std::string> list2{"john", "mary", "stian", "Stian"};
    REQUIRE(my::vector::contains(list2, "mary"));
    REQUIRE(my::vector::contains(list2, "stian"));
    REQUIRE(!my::vector::contains(list2, "John"));
}

TEST_CASE("my::vector::insert")
{
    std::vector<int> list{0,1,2,3,4,5,6,7,8,9};
    bool ok = my::vector::insert(list, 2, 22);
    REQUIRE(ok);
    REQUIRE(list.at(1) == 1);
    REQUIRE(list.at(2) == 22);
    REQUIRE(list.at(3) == 2);
    
    bool ok2 = my::vector::insert(list, 999, 22);
    REQUIRE(!ok2);
}