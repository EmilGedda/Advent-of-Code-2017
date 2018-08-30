#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int test() {

  std::regex re("([a-z]+)");
  std::string input(std::istreambuf_iterator<char>{std::cin}, {});
  std::vector<std::string> nodes(std::sregex_token_iterator(input.begin(), input.end(), re), {});
  std::sort(nodes.begin(), nodes.end());
  for(size_t i = 0; i < nodes.size(); i++) {
    if ((i == 0 || nodes[i - 1] != nodes[i]) && (i == nodes.size() - 1 || nodes[i] != nodes[i + 1]))
      std::cout << "Root node: " << nodes[i] << "\n";
  }
  
  return -1;
}
