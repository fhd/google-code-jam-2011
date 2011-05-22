#include <algorithm>
#include <istream>
#include <numeric>
#include <utility>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/math/common_factor.hpp>

inline bool is_in_harmony(long note, const std::vector<long>& sounds)
{
    for (std::vector<long>::const_iterator it = sounds.begin();
         it != sounds.end(); it++) {
        long other_note = *it;
        if (note % other_note > 0 && other_note % note > 0)
            return false;
    }
    return true;
}

inline long lowest_harmonic_frequency(const std::pair<long, long>& range,
                                      const std::vector<long>& sounds)
{
    // TODO: This solution is not fast enough for the large input.
    for (long i = range.first; i <= range.second; i++)
        if (is_in_harmony(i, sounds))
            return i;
    return 0;
}

inline void process_input(std::istream& input, std::ostream& output)
{
    std::string line;
    std::getline(input, line); // Ignore the first line.
    for (int i = 1; std::getline(input, line); i++) {
        std::vector<std::string> elements;
        boost::split(elements, line, boost::is_any_of(" "));
        std::pair<long, long> range(boost::lexical_cast<long>(elements[1]),
                                    boost::lexical_cast<long>(elements[2]));

        if (!std::getline(input, line))
            return;

        std::vector<long> sounds;
        typedef boost::split_iterator<std::string::iterator>
            string_split_iterator;
        string_split_iterator it = boost::make_split_iterator(
            line, boost::first_finder(" ", boost::is_equal()));
        for (; it != string_split_iterator(); it++)
            sounds.push_back(boost::lexical_cast<long>(*it));

        long lhf = lowest_harmonic_frequency(range, sounds);
        output << "Case #" << i << ": "
               << ((lhf > 0) ? boost::lexical_cast<std::string>(lhf) : "NO")
               << std::endl;
    }
}
