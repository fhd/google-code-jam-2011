#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>
#include <rpi.hpp>

using namespace boost::assign;
#include <iostream>
BOOST_AUTO_TEST_CASE(test_process_input)
{
    std::istringstream input("\
2\n\
3\n\
.10\n\
0.1\n\
10.\n\
4\n\
.11.\n\
0.00\n\
01.1\n\
.10.\n");
    std::ostringstream output;

    process_input(input, output);

    std::string expected = "\
Case #1:\n\
0.5\n\
0.5\n\
0.5\n\
Case #2:\n\
0.645833\n\
0.368056\n\
0.604167\n\
0.395833\n";
    BOOST_REQUIRE_EQUAL(output.str(), expected);
}

template<class T>
std::string collection_to_string(T collection)
{
    std::stringstream ss;
    for (typename T::iterator it = collection.begin(); it != collection.end();
         it++) {
        if (it != collection.begin())
            ss << ", ";
        ss << *it;
    }
    return ss.str();
}

template<class T>
bool is_close(T left, T right)
{
    return abs(left - right) <= 0.000001;
}

template<class T>
void require_collection_close(T left, T right)
{
    BOOST_REQUIRE_MESSAGE(boost::algorithm::equals(left, right,
                                                   &is_close<double>),
                          "critical check {" + collection_to_string(left)
                          + "} == {" + collection_to_string(right)
                          + "} failed");
}

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    boost::multi_array<Schedule_entry, 2> schedule(boost::extents[3][3]);
    schedule[0][0] = N;
    schedule[0][1] = W;
    schedule[0][2] = L;

    schedule[1][0] = L;
    schedule[1][1] = N;
    schedule[1][2] = W;

    schedule[2][0] = W;
    schedule[2][1] = L;
    schedule[2][2] = N;

    std::vector<double> expected;
    expected += 0.5, 0.5, 0.5;
    require_collection_close(expected, calculate_rpi(schedule));
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    boost::multi_array<Schedule_entry, 2> schedule(boost::extents[4][4]);
    schedule[0][0] = N;
    schedule[0][1] = W;
    schedule[0][2] = W;
    schedule[0][3] = N;

    schedule[1][0] = L;
    schedule[1][1] = N;
    schedule[1][2] = L;
    schedule[1][3] = L;

    schedule[2][0] = L;
    schedule[2][1] = W;
    schedule[2][2] = N;
    schedule[2][3] = W;

    schedule[3][0] = N;
    schedule[3][1] = W;
    schedule[3][2] = L;
    schedule[3][3] = N;

    std::vector<double> expected;
    expected += 0.645833333333, 0.368055555556, 0.604166666667, 0.395833333333;
    require_collection_close(expected, calculate_rpi(schedule));
}
