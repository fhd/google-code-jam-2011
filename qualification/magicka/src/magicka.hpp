#include <vector>
#include <boost/foreach.hpp>

struct Combination {
    char first;
    char second;
    char result;

    Combination(char first, char second, char result)
        : first(first), second(second), result(result) {}
};

struct Opposition {
    char first;
    char second;

    Opposition(char first, char second) : first(first), second(second) {}
};

inline char find_combination(char first, char second,
                             std::vector<Combination>& combinations)
{
    BOOST_FOREACH (Combination c, combinations)
        if ((first == c.first && second == c.second)
            || (first == c.second && second == c.first)) {
            return c.result;
        }
    return 0;
}

template<class T, class V>
inline bool collection_contains(T collection, V element)
{
    return std::find(collection.begin(), collection.end(), element) !=
        collection.end();
}

inline bool opposes(char new_element, std::vector<char>& elements,
                    std::vector<Opposition>& oppositions)
{
    BOOST_FOREACH (Opposition o, oppositions)
        if ((new_element == o.first && collection_contains(elements, o.second))
            || (new_element == o.second
                && collection_contains(elements, o.first)))
            return true;
    return false;
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
            char combination = find_combination(element, invoked.back(),
                                                combinations);
            if (combination != 0) {
                invoked.pop_back();
                invoked.push_back(combination);
                continue;
            } else if (opposes(element, invoked, oppositions)) {
                invoked.clear();
                continue;
            }
        }
        invoked.push_back(element);
    }
    return invoked;
}
