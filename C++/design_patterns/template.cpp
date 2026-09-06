#include "template.hpp"
#include <iostream>

int main()
{
  auto result1 = add<int>(3, 5); // 使用 int 类型
  auto result2 = add(2.5, 4.1);  // 使用 double
  std::cout << "Result 1: " << result1 << std::endl;
  std::cout << "Result 2: " << result2 << std::endl;
  return 0;
}