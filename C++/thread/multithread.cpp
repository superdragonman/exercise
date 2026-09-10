/**
 * @file multithread.cpp
 * @brief 多线程
 *
 * 尽量在线程自己的数据上工作，只有真正需要访问共享数据的时候才同步。
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

int counter = 0;
std::mutex mtx;
int a = 0;
int b = 0;
void worker(int &counter)
{
  int local_count = 0;
  for (int i = 0; i < 100000; ++i)
  {
    local_count++;
  }
  std::lock_guard<std::mutex> abc(mtx);
  counter += local_count;
}

void func()
{
  std::cout << "before lock" << std::endl;
  {
    std::lock_guard<std::mutex> abc(mtx);
    a++;
    b++;
  }
  std::cout << "after lock" << std::endl;
}
int main()
{
  // std::thread t1(worker, std::ref(counter));
  // std::thread t2(worker, std::ref(counter));
  // t1.join();
  // t2.join();
  // std::cout << "counter = " << counter << std::endl;

  std::thread t1(func);
  std::thread t2(func);
  t1.join();
  t2.join();
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;

  return 0;
}