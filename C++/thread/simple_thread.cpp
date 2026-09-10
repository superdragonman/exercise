/**
 * @file simple_thread.cpp
 * @brief 简单线程概念
 */

#include <iostream>
#include <thread>
// #include <functional> 如果用了std::ref()就需要包含这个头文件

int global = 10;
// std::thread 默认会把你传进去的参数保存一份，而不是自动保存成引用,所以要用std::ref(x)来传递引用
void worker(int &x)
{
  x = 100;
}

void worker2(int x)
{
  x = 100;
  std::cout << "x = " << x << std::endl;
  std::cout << "&x = " << &x << std::endl;
}

void worker3()
{
  int worker_local = 10;
  std::cout << "&worker_local = " << &worker_local << std::endl;
  std::cout << "&global = " << &global << std::endl;
}

int main()
{
  // std::cout << "global = " << global << std::endl;
  // // std::thread t(worker, std::ref(global));
  // // t.join();
  // std::thread t2(worker2, global);
  // t2.join();
  // std::cout << "global = " << global << std::endl;
  // std::cout << "&global = " << &global << std::endl;

  int main_local = 10;
  std::cout << "&global = " << &global << std::endl;
  std::cout << "&main_local = " << &main_local << std::endl;

  std::thread t3(worker3);
  t3.join();

  return 0;
}