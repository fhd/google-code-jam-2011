#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <freecell_statistics.hpp>

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    BOOST_REQUIRE(possible(1, 100, 50));
}
