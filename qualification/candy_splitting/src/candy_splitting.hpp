#include <vector>
#include <algorithm>

inline int patrick_sum(std::vector<int>& numbers)
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
        sum ^= numbers[i];
    return sum;
}

inline int sum(std::vector<int>& numbers)
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
        sum += numbers[i];
    return sum;
}

inline int candy_to_keep(std::vector<int>& candy)
{
    for (int i = 0; i < candy.size(); i++) {
        std::vector<int> sean(candy), patrick;
        for (int j = 0; j <= i; j++) {
            patrick.push_back(sean[j]);
            sean[j] = 0;
        }

        if (!patrick.empty() && !sean.empty()
            && patrick_sum(patrick) == patrick_sum(sean))
            return sum(sean);
    }
    return 0;
}
