#include <fstream>
#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include "goro_sort.hpp"

namespace fs = boost::filesystem;

void process(const std::string& input_file, const std::string& output_file)
{
   std::ifstream input(input_file.c_str());
   std::ofstream output(output_file.c_str());
   std::string line;
   std::getline(input, line); // Ignore the first line.
   int j = 1;
   for (int i = 0; std::getline(input, line); i++) {
      if (line.empty())
         continue;

      // Only every second line is relevant.
      if (i % 2 == 0)
          continue;

      std::vector<int> elements;
      typedef boost::split_iterator<std::string::iterator>
          string_split_iterator;
      for (string_split_iterator it = boost::make_split_iterator(
               line, boost::first_finder(" ", boost::is_equal()));
           it != string_split_iterator(); it++)
          elements.push_back(boost::lexical_cast<int>(*it));

      output << "Case #" << j++ << ": "
             << number_of_hits(elements)
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
