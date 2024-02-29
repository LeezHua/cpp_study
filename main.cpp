#include "cpplang.hpp"
#include <cassert>
#include <string_view>

int main(int, char **) {
  string s = "hello world";

  std::string_view ss(s);

  std::cout << ss << cr;

  return 0;
}