#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <candy_splitting.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_patrick_sum_1)
{
    std::vector<int> numbers;
    numbers += 4, 5;
    BOOST_REQUIRE_EQUAL(1, patrick_sum(numbers));
}

BOOST_AUTO_TEST_CASE(test_patrick_sum_2)
{
    std::vector<int> numbers;
    numbers += 7, 9;
    BOOST_REQUIRE_EQUAL(14, patrick_sum(numbers));
}

BOOST_AUTO_TEST_CASE(test_patrick_sum_3)
{
    std::vector<int> numbers;
    numbers += 50, 10;
    BOOST_REQUIRE_EQUAL(56, patrick_sum(numbers));
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

