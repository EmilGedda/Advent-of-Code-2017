#include <advent-of-code.hpp>
#include <cmath>
#include <iostream>
#include <numeric>

int test() {
  int pos;
  std::cin >> pos;
  int sqr = std::ceil(std::sqrt(pos));
  if ((sqr & 1) == 0)
    sqr++; // only allow odd sizes

  const int min = sqr >> 1;   // minimum amount of travel distance
  const int period = sqr - 1; // period of the extra distance from the center
  const int offset = (sqr * sqr - pos) % period;        // center of axis offset
  const int dist = std::abs(offset - period / 2) + min; // cummulative distance

  return dist;
}
