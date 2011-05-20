#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <candy_splitting.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_is_patrick_happy)
{
    std::vector<int> candy;
    candy += 5, 7, 9, 11;
    BOOST_REQUIRE(is_patrick_happy(candy));
}

BOOST_AUTO_TEST_CASE(test_is_patrick_not_happy)
{
    std::vector<int> candy;
    candy += 4, 5;
    BOOST_REQUIRE(!is_patrick_happy(candy));
}

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    std::vector<int> candy;
    candy += 1, 2, 3, 4, 5;
    BOOST_REQUIRE_EQUAL(0, candy_to_keep(candy));
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    std::vector<int> candy;
    candy += 3, 5, 6;
    BOOST_REQUIRE_EQUAL(11, candy_to_keep(candy));
}

BOOST_AUTO_TEST_CASE(test_permutation_1)
{
    std::vector<int> candy;
    candy += 3, 6, 5;
    BOOST_REQUIRE_EQUAL(11, candy_to_keep(candy));
}

BOOST_AUTO_TEST_CASE(test_permutation_2)
{
    std::vector<int> candy;
    candy += 5, 3, 6;
    BOOST_REQUIRE_EQUAL(11, candy_to_keep(candy));
}

