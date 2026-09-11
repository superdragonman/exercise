/**
 * @file condition_variable.cpp
 * @brief This file contains the implementation of condition variables in C++.
 */

#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>

bool ready = false;
std::mutex mtx;
std::condition_variable cv;

void worker()
{
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, []
          { return ready; });
  std::cout << "worker start" << std::endl;
}

int main()
{
  std::thread t(worker);
  {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
  }
  cv.notify_one();
  t.join();
  return 0;
}