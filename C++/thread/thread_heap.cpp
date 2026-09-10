/**
 * @file thread_heap.cpp
 * @brief 线程堆内存管理
 */

#include <iostream>
#include <thread>

void worker(int *q)
{
  *q = 100;
  std::cout << "*q = " << *q << std::endl;
  std::cout << "q = " << q << std::endl;
  std::cout << "&q = " << &q << std::endl;
}

void func(int *p)
{
  *p = 100;
}
int main()
{
  // int *ptr = new int(10);
  // std::cout << "*ptr = " << *ptr << std::endl;
  // std::cout << "ptr = " << ptr << std::endl;
  // std::cout << "&ptr = " << &ptr << std::endl;
  // std::thread t(worker, ptr);
  // t.join();
  // delete ptr;

  // int main_local = 10;
  // std::thread t(func, &main_local);
  // t.join();
  // std::cout << "main_local = " << main_local << std::endl;

  {
    int local = 10;
    std::thread t(func, &local);
    t.join();
    std::cout << "local = " << local << std::endl;
  }
  std::cout << "local out of scope" << std::endl;
  return 0;
}