#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <bot_trust.hpp>

BOOST_AUTO_TEST_CASE(test_empty)
{
    std::vector<std::pair<Robot, int> > sequence;
    BOOST_REQUIRE_EQUAL(0, time_required_for(sequence));
}

