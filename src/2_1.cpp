#include <advent-of-code.hpp>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

int main() {
  int sum = 0, curr;
  std::string line;
  while (std::getline(std::cin, line)) {
    int max = std::numeric_limits<int>::lowest();
    int min = std::numeric_limits<int>::max();
    std::istringstream ss(line);
    while (ss >> curr) {
      max = std::max(max, curr);
      min = std::min(min, curr);
    }
    sum += max - min;
  }
  std::cout << sum << '\n';
}
