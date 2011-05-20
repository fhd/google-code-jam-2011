#include <algorithm>
#include <numeric>
#include <vector>

inline int bitwise_xor(int a, int b)
{
    return a ^ b;
}

inline bool is_patrick_happy(std::vector<int>& candy) {
    return std::accumulate(candy.begin(), candy.end(), 0, &bitwise_xor) == 0;
}

inline int candy_to_keep(std::vector<int>& candy)
{
    return (!is_patrick_happy(candy)) ? 0
        : std::accumulate(candy.begin(), candy.end(),
                          -1 * *std::min_element(candy.begin(), candy.end()));
}
