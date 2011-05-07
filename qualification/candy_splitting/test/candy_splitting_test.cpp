#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <candy_splitting.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    std::vector<int> candy;
    candy += 1, 2, 3, 4, 5;
    BOOST_REQUIRE_EQUAL(0, candy_to_keep(candy));
}
