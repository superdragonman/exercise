/**
 * @file template_parameter_pack.hpp
 * @brief 模板参数包示例
 *
 * 可变参数模版, 关键在于...的使用
 */
#pragma once
#include <iostream>

template <typename... Args>
void countArgs(Args... args)
{
  std::cout << "arguments: " << sizeof...(args) << std::endl;
}

template <typename... Args>
void printAll(Args... args)
{
  ((std::cout << args << " "), ...);
  std::cout << std::endl;
}

template <typename... Args>
void sum(Args... args)
{
  std::cout << "sum:" << (... + args) << std::endl;
}

void target(int a, double b, const char *c)
{
  std::cout << "target: " << a << ", " << b << ", " << c << std::endl;
}
template <typename... Args>
void wrapper(Args... args)
{
  target(args...);
}

void printNumbers(int a, int b, int c)
{
  std::cout << a << " " << b << " " << c << std::endl;
}
template <typename... Args>
void doubleArgs(Args... args)
{
  printNumbers((args * 2)...);
}

template <typename... Args>
bool allTrue(Args... args)
{
  return (args && ...);
}

template <typename... Args>
bool anyTrue(Args... args)
{
  return (args || ...);
}

template <typename... Args>
void printLines(Args... args)
{
  ((std::cout << args << std::endl), ...);
}

template <typename T, typename... Args>
std::vector<T> makeVector(T first, Args... args)
{
  return std::vector<T>{first, args...};
}

template <typename... Args>
void log(Args... args)
{
  ((std::cout << args << " "), ...);
  std::cout << std::endl;
}