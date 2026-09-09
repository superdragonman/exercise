#include <iostream>
#include "template_parameter_pack.hpp"

int main()
{
  std::cout << "***** countArgs *****" << std::endl;
  countArgs(1, 2.5, "sdf");
  std::cout << std::endl;

  std::cout << "***** printAll *****" << std::endl;
  printAll("sg", "th", 3, 2.5);
  std::cout << std::endl;

  std::cout << "***** sum *****" << std::endl;
  sum(1, 2, 3, 4);
  std::cout << std::endl;

  std::cout << "***** wrapper *****" << std::endl;
  wrapper(1, 2.5, "sdf");
  std::cout << std::endl;

  std::cout << "***** doubleArgs *****" << std::endl;
  doubleArgs(1, 2, 3);
  std::cout << std::endl;

  std::cout << "***** allTrue *****" << std::endl;
  std::cout << allTrue(true, true, true) << std::endl;
  std::cout << allTrue(true, false, true) << std::endl;
  std::cout << std::endl;

  std::cout << "***** anyTrue *****" << std::endl;
  std::cout << anyTrue(true, true, true) << std::endl;
  std::cout << anyTrue(true, false, true) << std::endl;
  std::cout << std::endl;

  std::cout << "***** printLines" << std::endl;
  printLines("line1", "line2", "line3");
  std::cout << std::endl;

  std::cout << "***** makeVectors *****" << std::endl;
  auto v1 = makeVector(1, 2, 3);
  auto v2 = makeVector("a", "b", "c");
  std::cout << "v1: ";
  for (const auto &e : v1)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  std::cout << "v2: ";
  for (const auto &e : v2)
  {
    std::cout << e << " ";
  }
  std::cout << std::endl
            << std::endl;

  std::cout << "***** log ******" << std::endl;
  log("name =", "Tom", "age =", 20);
  std::cout << std::endl;
  return 0;
}