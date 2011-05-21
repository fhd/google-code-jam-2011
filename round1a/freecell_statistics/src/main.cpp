#include <fstream>
#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include "freecell_statistics.hpp"

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

      // TODO: I/O
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
