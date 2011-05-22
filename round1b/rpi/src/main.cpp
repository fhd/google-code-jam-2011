#include <iostream>
#include <fstream>
#include <string>

#include <boost/filesystem.hpp>

#include "rpi.hpp"

namespace fs = boost::filesystem;

int main(int argc, char *argv[])
{
   try {
      if (argc != 3) {
         std::cerr << "Usage: " << fs::basename(argv[0]) << " INPUT OUTPUT"
                   << std::endl;
         return 1;
      }
      std::ifstream input(argv[1]);
      std::ofstream output(argv[2]);
      process_input(input, output);
   } catch (std::exception& e) {
      std::cerr << "Caught an exception: " << e.what() << std::endl;
      return 1;
   }

   return 0;
}
