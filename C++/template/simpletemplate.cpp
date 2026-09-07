#include <iostream>
#include "simpletemplate.hpp"

int main()
{
  int a = 5, b = 10;
  double x = 3.14, y = 2.71;

  std::cout << "Sum of integers: " << add(a, b) << std::endl;
  std::cout << "Sum of doubles: " << add(x, y) << std::endl;

  return 0;
}