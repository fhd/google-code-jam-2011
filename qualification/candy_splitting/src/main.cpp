#include <fstream>
#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include "candy_splitting.hpp"

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

      std::vector<std::string> elements;
      boost::split(elements, line, boost::is_any_of(" "));

      std::vector<int> candy;
      BOOST_FOREACH (std::string s, elements)
          candy.push_back(boost::lexical_cast<int>(s));

      int seans_candy = candy_to_keep(candy);
      output << "Case #" << j++ << ": "
             << (seans_candy > 0
                 ? boost::lexical_cast<std::string>(seans_candy) : "NO")
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
