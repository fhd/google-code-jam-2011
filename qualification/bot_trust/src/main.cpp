#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "bot_trust.hpp"

namespace fs = boost::filesystem;

void process(const std::string& input_file, const std::string& output_file)
{
   std::ifstream input(input_file.c_str());
   std::ofstream output(output_file.c_str());
   std::string line;
   std::getline(input, line); // Ignore the first line.
   for (int i = 1; std::getline(input, line); i++) {
      if (line.empty())
         continue;

      std::vector<std::pair<Robots, int> > sequence;
      typedef boost::split_iterator<std::string::iterator>
          string_split_iterator;
      string_split_iterator it = boost::make_split_iterator(
          line, boost::first_finder(" ", boost::is_equal()));
      for (it++; it != string_split_iterator(); it++) {
          std::pair<Robots, int> button;
          button.first = (*it == std::string("O")) ? ORANGE : BLUE;
          it++;
          if (it == string_split_iterator())
              break;
          button.second = boost::lexical_cast<int>(*it);
          sequence.push_back(button);
      }
      output << "Case #" << i << ": "
             << time_required_for(sequence)
             << std::endl;
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
