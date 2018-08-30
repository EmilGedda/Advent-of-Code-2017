#include <iostream>
#include <chrono>

#define STR_EXPAND(x) #x
#define STR(x) STR_EXPAND(x)
extern int test();

int main() {
  std::ios::sync_with_stdio(false);
  using namespace std::chrono;
  auto start  = steady_clock::now();
  auto answer = test();
  auto end    = steady_clock::now();

  std::cout << "Running solution: " STR(SOLUTION) << "\n"
    << "Answer: " << answer << "\nExecution time: " 
    << duration_cast<duration<float>>(end - start).count() << "s\n";

}
