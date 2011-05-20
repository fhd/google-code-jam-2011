#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <goro_sort.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    std::vector<int> elements;
    elements += 2, 1;
    BOOST_REQUIRE_EQUAL(2, number_of_hits(elements));
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    std::vector<int> elements;
    elements += 1, 3, 2;
    BOOST_REQUIRE_EQUAL(2, number_of_hits(elements));
}

BOOST_AUTO_TEST_CASE(test_sample_3)
{
    std::vector<int> elements;
    elements += 2, 1, 4, 3;
    BOOST_REQUIRE_EQUAL(4, number_of_hits(elements));
}
