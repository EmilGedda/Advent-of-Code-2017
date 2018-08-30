#include <advent-of-code.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int test() {

  int idx = 0, steps = 0;
  std::vector<int> instructions(std::istream_iterator<int>(std::cin),
                                std::istream_iterator<int>{});
  while (idx < instructions.size()) {
    idx += instructions[idx]++;
    steps++;
  }
  return steps;
}
