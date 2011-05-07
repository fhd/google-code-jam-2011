#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "magicka.hpp"

namespace fs = boost::filesystem;

Combination parse_combination(const std::string& input)
{
    return Combination(input[0], input[1], input[2]);
}

Opposition parse_opposition(const std::string& input)
{
    return Opposition(input[0], input[1]);
}

template<class T>
std::string collection_to_string(T collection)
{
    std::stringstream ss;
    for (typename T::iterator it = collection.begin(); it != collection.end();
         it++) {
        if (it != collection.begin())
            ss << ", ";
        ss << *it;
    }
    return ss.str();
}

void process(const std::string& input_file, const std::string& output_file)
{
   std::ifstream input(input_file.c_str());
   std::ofstream output(output_file.c_str());
   std::string line;
   std::getline(input, line); // Ignore the first line.
   for (int i = 1; std::getline(input, line); i++) {
      if (line.empty())
         continue;

      typedef boost::split_iterator<std::string::iterator>
          string_split_iterator;
      string_split_iterator it = boost::make_split_iterator(
          line, boost::first_finder(" ", boost::is_equal()));

      int num_combinations = boost::lexical_cast<int>(*it++);
      std::vector<Combination> combinations;
      for (int j = 0; j < num_combinations; j++) {
          std::string s = boost::lexical_cast<std::string>(*it++);
          combinations.push_back(parse_combination(s));
      }

      int num_oppositions = boost::lexical_cast<int>(*it++);
      std::vector<Opposition> oppositions;
      for (int j = 0; j < num_oppositions; j++) {
          std::string s = boost::lexical_cast<std::string>(*it++);
          oppositions.push_back(parse_opposition(s));
      }

      int num_elements = boost::lexical_cast<int>(*it++);
      std::string element_str = boost::lexical_cast<std::string>(*it++);
      std::vector<char> elements;
      for (int j = 0; j < num_elements; j++)
          elements.push_back(element_str[j]);

      output << "Case #" << i << ": ["
             << collection_to_string(invoke(elements, combinations,
                                            oppositions))
             << "]" << std::endl;
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
