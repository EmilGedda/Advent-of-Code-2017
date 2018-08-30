#include <advent-of-code.hpp>
#include <iostream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

int test() {
  int steps = 0;
  std::vector<std::size_t> banks(std::istream_iterator<std::size_t>(std::cin),
                                 std::istream_iterator<std::size_t>{});

  std::unordered_map<int, bool> not_a_bloom_filter;

  // Modified Boost hash_combine
  auto hash_combine = [](std::size_t seed, const auto v) {
    return seed ^ (v + 0x9e3779b9 + (seed << 6) + (seed >> 2));
  };

  bool duplicate = false;
  while (!duplicate) {
    auto max_iterator = std::max_element(banks.begin(), banks.end());
    int index = std::distance(banks.begin(), max_iterator);
    auto distribute = *max_iterator;
    *max_iterator = 0;
    index = (index + 1) % banks.size();

    //could be optimized into a single pass
    while(distribute > 0){
      banks[index]++;
      index = (index + 1) % banks.size();
      distribute--;
    }

    std::size_t hash =
        std::accumulate(banks.begin(), banks.end(), 0, hash_combine);
    duplicate = !not_a_bloom_filter.emplace(hash, true).second;
    steps++;
  }

  return steps;
}
