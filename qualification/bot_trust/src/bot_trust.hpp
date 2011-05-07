#include <vector>
#include <utility>
#include <queue>
#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>

enum Robots {
    ORANGE,
    BLUE
};

struct Robot {
    int pos;
    std::queue<int> buttons;

    Robot() : pos(1) {}
};

inline int move_toward(int start, int goal) {
    if (start == goal)
        return start;
    return (start < goal) ? start + 1 : start - 1;
}

inline void move_robots(std::vector<std::pair<Robots, int> >::iterator& it,
                        Robot& orange, Robot& blue)
{
    bool orange_active = it->first == ORANGE;
    Robot& active_robot = orange_active ? orange : blue;
    Robot& inactive_robot = orange_active ? blue : orange;

    int current_button = it->second;
    if (active_robot.pos == current_button) {
        // Button pressed
        if (active_robot.buttons.size() > 0)
            active_robot.buttons.pop();
        it++;
    } else
        active_robot.pos = move_toward(active_robot.pos, current_button);

    inactive_robot.pos = move_toward(inactive_robot.pos,
                                     inactive_robot.buttons.front());
}

inline int time_required_for(std::vector<std::pair<Robots, int> >& sequence)
{
    if (sequence.size() == 0)
        return 0;

    Robot orange, blue;
    typedef std::pair<Robots, int> robot_pair;
    BOOST_FOREACH (robot_pair p, sequence)
        if (p.first == ORANGE)
            orange.buttons.push(p.second);
        else
            blue.buttons.push(p.second);

    int time = 0;
    for (std::vector<robot_pair>::iterator it = sequence.begin();
         it != sequence.end(); time++)
        move_robots(it, orange, blue);
    return time;
}
