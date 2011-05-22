#include <algorithm>
#include <istream>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/multi_array.hpp>

enum Tile {B, W, R1, R2};
typedef boost::multi_array<Tile, 2> Picture;

inline bool replace_blue_tiles(Picture& picture)
{
    if (picture.size() < 2 || picture[0].size() < 2) {
        for (int i = 0; i < picture.size(); i++)
            for (int j = 0; j < picture[0].size(); j++)
                if (picture[i][j] == B)
                    return false;
        return true;
    }

    for (int i = 0; i < picture.size() - 1; i++)
        for (int j = 0; j < picture[i].size() - 1; j++) {
            if (picture[i][j] == B
                && picture[i][j + 1] == B
                && picture[i + 1][j] == B
                && picture[i + 1][j + 1] == B) {
                picture[i][j] = R1;
                picture[i][j + 1] = R2;
                picture[i + 1][j] = R2;
                picture[i + 1][j + 1] = R1;
            }
            if (picture[i][j] == B)
                return false;
        }

    int last_i = picture.size() - 1;
    int last_j = picture[0].size() - 1;
    for (int i = 0; i < last_i; i++)
        if (picture[i][last_j] == B)
            return false;
    for (int j = 0; j < last_j; j++)
        if (picture[last_i][j] == B)
            return false;

    return true;
}

inline Tile char_to_tile(char c)
{
    switch (c) {
    case '#':
        return B;
    case '/':
        return R1;
    case '\\':
        return R2;
    }
    return W;
}

inline char tile_to_char(const Tile& tile)
{
    switch (tile) {
    case B:
        return '#';
    case R1:
        return '/';
    case R2:
        return '\\';
    }
    return '.';
}

inline std::string picture_to_string(const Picture& picture)
{
    std::stringstream ss;
    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++)
            ss << tile_to_char(picture[i][j]);
        ss << std::endl;
    }
    return ss.str();
}

inline void process_input(std::istream& input, std::ostream& output)
{
   std::string line;
   std::getline(input, line); // Ignore the first line.
   for (int i = 1; std::getline(input, line); i++) {
       std::vector<std::string> elements;
       boost::split(elements, line, boost::is_any_of(" "));
       int num_rows = boost::lexical_cast<int>(elements[0]),
           num_cols = boost::lexical_cast<int>(elements[1]);

       Picture picture(boost::extents[num_rows][num_cols]);
       for (int j = 0; j < num_rows && std::getline(input, line); j++)
           for (int k = 0; k < num_cols; k++)
               picture[j][k] = char_to_tile(line[k]);

       bool success = replace_blue_tiles(picture);
       output << "Case #" << i << ":" << std::endl
              << ((success) ? picture_to_string(picture) : "Impossible\n");
   }
}
