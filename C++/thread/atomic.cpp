/**
 * @file atomic.cpp
 * @brief 原子操作
 */

#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0);
std::atomic<int> a(0);
std::atomic<int> b(0);

void worker()
{
  for (int i = 0; i < 100000; ++i)
  {
    counter++;
  }
}
void read()
{
  std::cout << "a = " << a.load() << std::endl;
  std::cout << "b = " << b.load() << std::endl;
}
void store()
{
  a.store(1);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  b.store(1);
}

int main()
{
  // std::thread t1(worker);
  // std::thread t2(worker);
  // t1.join();
  // t2.join();
  // std::cout << "counter = " << counter << std::endl;

  // std::atomic<int> x(10);
  // std::cout << "x = " << x.load() << std::endl;
  // x.store(100);
  // std::cout << "x = " << x.load() << std::endl;

  // std::thread t1(store);
  // std::thread t2(read);
  // t1.join();
  // t2.join();

  std::atomic<int> x(10);
  int old = x.fetch_add(5);
  std::cout << "old = " << old << std::endl;
  std::cout << "x = " << x.load() << std::endl;

  return 0;
}