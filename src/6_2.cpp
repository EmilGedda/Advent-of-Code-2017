#include <advent-of-code.hpp>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

void redistribute(std::vector<int> &banks) {
  auto max_iterator = std::max_element(banks.begin(), banks.end());
  int index = std::distance(banks.begin(), max_iterator);
  auto distribute = *max_iterator;
  *max_iterator = 0;
  index = (index + 1) % banks.size();
  // could be optimized into a single pass
  while (distribute > 0) {
    banks[index]++;
    index = (index + 1) % banks.size();
    distribute--;
  }
}

int main() {
  std::vector<std::int> banks(std::istream_iterator<std::int>(std::cin),
                              std::istream_iterator<std::int>{});
  std::unordered_map<int, bool> not_a_bloom_filter;

  // Modified Boost hash_combine
  auto hash_combine = [](std::size_t seed, const auto v) {
    return seed ^ (v + 0x9e3779b9 + (seed << 6) + (seed >> 2));
  };

  int duplicate = 0, steps = 0;
  while (duplicate < 2) {
    redistribute(banks); 
    if (duplicate >= 1)
      steps++;

    auto hash = std::accumulate(banks.begin(), banks.end(), 0, hash_combine);
    auto dup = !not_a_bloom_filter.emplace(hash, true).second;

    // could be optimized to only check for start hash
    if (dup) {
      not_a_bloom_filter.clear();
      not_a_bloom_filter.emplace(hash, true);
      duplicate++;
    }
  }

  std::cout << steps << '\n';
}
