#include <fstream>
#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include "rpi.hpp"

namespace fs = boost::filesystem;

Schedule_entry parse_schedule_entry(char entry)
{
    switch (entry) {
    case '0':
        return L;
    case '1':
        return W;
    }
    return N;
}

void process(const std::string& input_file, const std::string& output_file)
{
   std::ifstream input(input_file.c_str());
   std::ofstream output(output_file.c_str());
   std::string line;
   std::getline(input, line); // Ignore the first line.
   for (int i = 1; std::getline(input, line); i++) {
      int num_teams = boost::lexical_cast<int>(line);
      boost::multi_array<Schedule_entry, 2>
          schedule(boost::extents[num_teams][num_teams]);
      for (int j = 0; j < num_teams && std::getline(input, line); j++)
          for (int k = 0; k < line.length(); k++)
              schedule[j][k] = parse_schedule_entry(line[k]);
      std::vector<double> rpis = calculate_rpi(schedule);
      output << "Case #" << i << ":" << std::endl;
      BOOST_FOREACH (double rpi, rpis)
          output << rpi << std::endl;
   }
}


int main(int argc, char *argv[])
{
   try {
      if (argc != 3) {
         std::cerr << "Usage: " << fs::basename(argv[0]) << " INPUT OUTPUT"
                   << std::endl;
         return 1;
      }
      process(argv[1], argv[2]);
   } catch (std::exception& e) {
      std::cerr << "Caught an exception: " << e.what() << std::endl;
      return 1;
   }

   return 0;
}
