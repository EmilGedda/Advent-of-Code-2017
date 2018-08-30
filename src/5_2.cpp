#include <advent-of-code.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int test() {

  size_t idx = 0, steps = 0;
  std::vector<int> instructions(std::istream_iterator<int>(std::cin),
                                std::istream_iterator<int>{});
  while (idx >= 0 && idx < instructions.size()) {
    auto &curr = instructions[idx];
    idx += curr;
    curr += curr >= 3 ? -1 : 1;
    steps++;
  }
  return steps;
}
