#include <advent-of-code.hpp>
#include <iostream>

// Deliberate slow impl, to compare runtime of templates vs
// regular non-optimizable variables

uint64_t generator(uint64_t g, uint64_t factor, uint64_t mod) {
  return (g * factor) % mod;
}

int main() {
  uint64_t a = 516;
  uint64_t b = 190;
  uint64_t ctr = 0;
  uint64_t fact_a, fact_b, mod;
  std::cin >> fact_a >> fact_b >> mod;
  for (int i = 0; i <= 5'000'000; i++) {
    do {
      a = generator(a, fact_a, mod);
    } while ((a % 4) != 0);
    do {
      b = generator(b, fact_b, mod);
    } while ((b % 8) != 0);
    ctr += uint16_t(a) == uint16_t(b);
  }
  std::cout << ctr << '\n';
}
