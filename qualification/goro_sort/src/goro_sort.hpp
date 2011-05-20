#include <algorithm>
#include <vector>

inline int number_of_hits(std::vector<int>& elements)
{
    int hits = 0;
    std::vector<int> sorted_elements(elements);
    std::sort(sorted_elements.begin(), sorted_elements.end());
    for (int i = 0; i < elements.size(); i++)
        if (elements[i] != sorted_elements[i])
            hits++;
    return hits;
}
