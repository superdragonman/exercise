/**
 * @file process.cpp
 * @brief 进程概念
 */

#include <iostream>
int global = 10;
int main()
{
  int partial = 20;
  std::cout << "Program is running" << std::endl;
  std::cout << "全局变量为 = " << global << std::endl;
  std::cout << "局部变量为 = " << partial << std::endl;

  std::cout << "请输入一个数,将全局变量修改为它" << std::endl;
  std::cin >> global;
  std::cout << "全局变量为 = " << global << std::endl;
  std::cout << "请输入一个数,将局部变量修改为它" << std::endl;
  std::cin >> partial;
  std::cout << "全局变量为 = " << global << std::endl;
  std::cout << "局部变量为 = " << partial << std::endl;
  std::cin >> std::ws;
  return 0;
}