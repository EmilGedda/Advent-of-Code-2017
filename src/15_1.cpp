#include <advent-of-code.hpp>
#include <iostream>

template <uint64_t factor, uint64_t mod = 2147483647>
uint64_t generator(uint64_t g) {
  return (g * factor) % mod;
}

int main() {
  uint64_t a = 516;
  uint64_t b = 190;
  uint64_t ctr = 0;
  for (int i = 0; i <= 40'000'000; i++) {
    a = generator<16807>(a);
    b = generator<48271>(b);
    ctr += uint16_t(a) == uint16_t(b);
  }
  std::cout << ctr << '\n';
}
