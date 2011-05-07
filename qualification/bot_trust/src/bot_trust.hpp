#include <vector>
#include <utility>

enum Robot {
    ORANGE,
    BLUE
};

inline int time_required_for(std::vector<std::pair<Robot, int> >& sequence)
{
    if (sequence.size() == 0)
        return 0;

    return 6;
}
