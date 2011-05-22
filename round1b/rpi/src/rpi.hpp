#include <algorithm>
#include <map>
#include <vector>
#include <boost/multi_array.hpp>

enum Schedule_entry {W, L, N};

inline void erase_if_present(std::vector<int>& collection, int element)
{
    std::vector<int>::iterator it = std::find(collection.begin(),
                                              collection.end(), element);
    if (it != collection.end())
        collection.erase(it);
}

inline std::vector<double> calculate_rpi(const boost::multi_array<
                                             Schedule_entry, 2>& schedule)
{
    std::map<int, std::vector<int> > opponents, won;
    for (int i = 0; i < schedule.size(); i++)
        for (int j = 0; j < schedule[i].size(); j++) {
            Schedule_entry e = schedule[i][j];
            if (e == N)
                continue;

            opponents[i].push_back(j);
            if (e == W)
                won[i].push_back(j);
        }

    std::map<int, double> wps, owps;
    for (int i = 0; i < schedule.size(); i++) {
        int num_opponents = opponents[i].size();
        wps[i] = (double) won[i].size() / num_opponents;
        double owp = 0;
        for (int j = 0; j < num_opponents; j++) {
            int opponent = opponents[i][j];
            std::vector<int> opponent_opponents(opponents[opponent]),
                opponent_won(won[opponent]);
            erase_if_present(opponent_opponents, i);
            erase_if_present(opponent_won, i);
            owp += (double) opponent_won.size() / opponent_opponents.size();
        }
        owp /= num_opponents;
        owps[i] = owp;
    }

    std::vector<double> rpis;
    for (int i = 0; i < schedule.size(); i++) {
        int num_opponents = opponents[i].size();
        double oowp = 0;
        for (int j = 0; j < num_opponents; j++)
            oowp += owps[opponents[i][j]];
        oowp /= num_opponents;
        
        double wp = wps[i], owp = owps[i];
        rpis.push_back(0.25 * wp + 0.5 * owp + 0.25 * oowp);
    }
    return rpis;
}
