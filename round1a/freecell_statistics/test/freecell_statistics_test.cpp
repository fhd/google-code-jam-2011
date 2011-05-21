#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <freecell_statistics.hpp>

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    BOOST_REQUIRE(is_possible(1, 100, 50));
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    BOOST_REQUIRE(!is_possible(10, 10, 100));
}

BOOST_AUTO_TEST_CASE(test_sample_3)
{
    BOOST_REQUIRE(is_possible(9, 80, 56));
}

BOOST_AUTO_TEST_CASE(test_odd_percentage)
{
    BOOST_REQUIRE(!is_possible(2, 87, 64));
}

BOOST_AUTO_TEST_CASE(test_zero_won_total_but_greater_zero_won_today)
{
    BOOST_REQUIRE(!is_possible(10, 10, 0));
}

BOOST_AUTO_TEST_CASE(test_large_number)
{
    BOOST_REQUIRE(is_possible(320147558007552, 78, 83));
}
