#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>
#include <square_tiles.hpp>

using namespace boost::assign;
#include <iostream>
BOOST_AUTO_TEST_CASE(test_process_input)
{
    std::istringstream input("");
    std::ostringstream output;

    process_input(input, output);

    std::string expected = "";
    BOOST_REQUIRE_EQUAL(output.str(), expected);
}

BOOST_AUTO_TEST_CASE(test_picture_to_string)
{
    Picture picture(boost::extents[3][3]);
    picture[0][0] = W;
    picture[0][1] = B;
    picture[0][2] = W;

    picture[1][0] = RTL;
    picture[1][1] = RTR;
    picture[1][2] = W;

    picture[2][0] = RBL;
    picture[2][1] = RBR;
    picture[2][2] = W;

    std::string expected = "\
.#.\n\
/\\.\n\
\\/.\n";
    BOOST_REQUIRE_EQUAL(expected, picture_to_string(picture));
}

void require_picture_equal(const Picture& left, const Picture& right)
{
    BOOST_REQUIRE_MESSAGE(boost::algorithm::equals(left, right),
                          "critical check {\n" + picture_to_string(left)
                          + "} == {\n" + picture_to_string(right)
                          + "} failed");
}

BOOST_AUTO_TEST_CASE(test_sample_1)
{
    Picture picture(boost::extents[2][3]);
    picture[0][0] = B;
    picture[0][1] = B;
    picture[0][2] = B;

    picture[1][0] = B;
    picture[1][1] = B;
    picture[1][2] = B;

    BOOST_REQUIRE(!replace_blue_tiles(picture));
}

BOOST_AUTO_TEST_CASE(test_simple)
{
    Picture picture(boost::extents[2][3]);
    picture[0][0] = B;
    picture[0][1] = B;
    picture[0][2] = W;

    picture[1][0] = B;
    picture[1][1] = B;
    picture[1][2] = W;

    BOOST_REQUIRE(replace_blue_tiles(picture));

    Picture expected(boost::extents[2][3]);
    expected[0][0] = RTL;
    expected[0][1] = RTR;
    expected[0][2] = W;

    expected[1][0] = RBL;
    expected[1][1] = RBR;
    expected[1][2] = W;
    require_picture_equal(expected, picture);
}

BOOST_AUTO_TEST_CASE(test_sample_2)
{
    Picture picture(boost::extents[4][5]);
    picture[0][0] = W;
    picture[0][1] = B;
    picture[0][2] = B;
    picture[0][3] = W;
    picture[0][4] = W;

    picture[1][0] = W;
    picture[1][1] = B;
    picture[1][2] = B;
    picture[1][3] = B;
    picture[1][4] = B;

    picture[2][0] = W;
    picture[2][1] = B;
    picture[2][2] = B;
    picture[2][3] = B;
    picture[2][4] = B;

    picture[3][0] = W;
    picture[3][1] = B;
    picture[3][2] = B;
    picture[3][3] = W;
    picture[3][4] = W;

    BOOST_REQUIRE(replace_blue_tiles(picture));

    Picture expected(boost::extents[4][5]);
    expected[0][0] = W;
    expected[0][1] = RTL;
    expected[0][2] = RTR;
    expected[0][3] = W;
    expected[0][4] = W;

    expected[1][0] = W;
    expected[1][1] = RBL;
    expected[1][2] = RBR;
    expected[1][3] = RTL;
    expected[1][4] = RTR;

    expected[2][0] = W;
    expected[2][1] = RTL;
    expected[2][2] = RTR;
    expected[2][3] = RBL;
    expected[2][4] = RBR;

    expected[3][0] = W;
    expected[3][1] = RBL;
    expected[3][2] = RBR;
    expected[3][3] = W;
    expected[3][4] = W;

    require_picture_equal(expected, picture);
}
