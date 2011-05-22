#include <algorithm>
#include <istream>
#include <iostream>
#include <sstream>
#include <boost/multi_array.hpp>

enum Tile {B, W, RTL, RTR, RBL, RBR};
typedef boost::multi_array<Tile, 2> Picture;

inline std::string picture_to_string(const Picture&);

inline bool replace_blue_tiles(Picture& picture)
{
    if (picture.size() < 2 || picture[0].size() < 2)
        return false;

    for (int i = 0; i < picture.size() - 1; i++)
        for (int j = 0; j < picture[i].size() - 1; j++) {
            if (picture[i][j] == B
                && picture[i][j + 1] == B
                && picture[i + 1][j] == B
                && picture[i + 1][j + 1] == B) {
                picture[i][j] = RTL;
                picture[i][j + 1] = RTR;
                picture[i + 1][j] = RBL;
                picture[i + 1][j + 1] = RBR;
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

inline char tile_to_char(const Tile& tile)
{
    switch (tile) {
    case B:
        return '#';
    case RTL:
    case RBR:
        return '/';
    case RTR:
    case RBL:
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
       // TODO: I/O
   }
}
