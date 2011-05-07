#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>
#include <magicka.hpp>

using namespace boost::assign;

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
void require_collection_equals(T left, T right)
{
    BOOST_REQUIRE_MESSAGE(boost::algorithm::equals(left, right),
                          "critical check {" + collection_to_string(left)
                          + "} == {" + collection_to_string(right)
                          + "} failed");
}

BOOST_AUTO_TEST_CASE(test_empty)
{
    std::vector<char> elements;
    BOOST_REQUIRE(invoke(elements).empty());
}

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    std::vector<char> elements;
    elements += 'E', 'A';
    std::vector<char> expected;
    expected += 'E', 'A';
    require_collection_equals(expected, invoke(elements));
}
