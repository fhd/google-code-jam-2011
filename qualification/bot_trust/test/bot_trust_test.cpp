#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <bot_trust.hpp>

typedef std::pair<Robot, int> robot_pair;
typedef std::vector<robot_pair > robot_sequence;

BOOST_AUTO_TEST_CASE(test_empty)
{
    robot_sequence sequence;
    BOOST_REQUIRE_EQUAL(0, time_required_for(sequence));
}

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    robot_sequence sequence;
    sequence.push_back(robot_pair(ORANGE, 2));
    sequence.push_back(robot_pair(BLUE, 1));
    sequence.push_back(robot_pair(BLUE, 2));
    sequence.push_back(robot_pair(ORANGE, 4));
    BOOST_REQUIRE_EQUAL(6, time_required_for(sequence));
}

