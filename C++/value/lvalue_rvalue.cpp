#include <iostream>
#include "lvalue_rvalue.hpp"

void target(int &a)
{
  std::cout << "左值引用: " << a << std::endl;
}

void target(int &&a)
{
  std::cout << "右值引用: " << a << std::endl;
}

int main()
{
  int &&a = 10;
  target(a);  // 左值引用
  target(20); // 右值引用
  std::cout << std::endl;

  wrapper(a);  // 左值引用
  wrapper(30); // 右值引用

  return 0;
}