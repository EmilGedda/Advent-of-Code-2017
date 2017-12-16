#pragma once

#include <iostream>

// Constructor class, run common functions before main
struct Prelude {

  Prelude() { std::ios_base::sync_with_stdio(false); }

  ~Prelude() {}

};

static Prelude prelude;
