#include <advent-of-code.hpp>
#include <iostream>

int main()
{
  int ctr = 0;
  std::string input;
  std::cin >> input;
  int offset = input.size()>>1;
  for(int i = 0; i < input.size(); i++) {
    if (input[i] == input[(i+offset) % input.size()])
      ctr += input[i] - '0';
  }
  std::cout << ctr << '\n';
}
