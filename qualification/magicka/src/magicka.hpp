#include <vector>
#include <boost/foreach.hpp>

struct Combination {
    char first;
    char second;
    char result;

    Combination(char first, char second, char result) :
        first(first), second(second), result(result) {}
};

struct Opposition {
    char first;
    char second;

    Opposition(char first, char second) : first(first), second(second) {}
};

inline char find_combination(std::vector<Combination> combination, char first,
                             char second)
{
    bool was_combination = false;
    BOOST_FOREACH (Combination c, combination)
        if ((first == c.first && second == c.second)
            || (first == c.second && second == c.first)) {
            return c.result;
        }
    return 0;
}

inline std::vector<char> invoke(std::vector<char>& elements,
                                std::vector<Combination>& combinations,
                                std::vector<Opposition>& oppositions)
{
    if (elements.size() == 0
        || (combinations.size() == 0 && oppositions.size() == 0))
        return elements;

    std::vector<char> invoked;
    BOOST_FOREACH (char element, elements) {
        if (invoked.size() > 0) {
            char combination = find_combination(combinations, element,
                                                invoked.back());
            if (combination != 0) {
                invoked.pop_back();
                invoked.push_back(combination);
                continue;
            }
        }
        invoked.push_back(element);
    }
    return invoked;
}
