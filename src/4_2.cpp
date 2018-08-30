#include <advent-of-code.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int test() {

  std::string line;
  int valid = 0;
  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    std::string word;
    std::unordered_map<std::string, bool> not_a_bloom_filter;
    bool inserted = true;
    while (ss >> word && inserted) {
      std::sort(word.begin(), word.end());
      inserted = not_a_bloom_filter.emplace(word, true).second;
    }
    valid += inserted;
  }
  return valid;
}
