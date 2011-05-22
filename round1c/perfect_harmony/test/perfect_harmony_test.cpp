#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>
#include <perfect_harmony.hpp>

using namespace boost::assign;

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    std::pair<long, long> range(2, 100);
    std::vector<long> sounds;
    sounds += 3, 5, 7;
    BOOST_REQUIRE_EQUAL(0, lowest_harmonic_frequency(range, sounds));
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    std::pair<long, long> range(8, 16);
    std::vector<long> sounds;
    sounds += 20, 5, 2;
    BOOST_REQUIRE_EQUAL(10, lowest_harmonic_frequency(range, sounds));
}

BOOST_AUTO_TEST_CASE(test_process_input)
{
    std::istringstream input("\
2\n\
3 2 100\n\
3 5 7\n\
4 8 16\n\
1 20 5 2\n");

    std::ostringstream output;

    process_input(input, output);

    std::string expected = "\
Case #1: NO\n\
Case #2: 10\n";

    BOOST_REQUIRE_EQUAL(output.str(), expected);
}
