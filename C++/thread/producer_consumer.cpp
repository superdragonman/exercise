/**
 * @file producer_consumer.cpp
 * @brief This file contains the implementation of the producer-consumer problem using condition variables in C++.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>

std::mutex mtx;
std::condition_variable cv;
std::queue<std::function<void()>> buffer;
bool done = false;

// void producer()
// {
//   for (int i = 0; i < 10; ++i)
//   {
//     {
//       std::lock_guard<std::mutex> lock(mtx);
//       buffer.push(i);
//     }
//     cv.notify_one();
//   }
//   {
//     std::lock_guard<std::mutex> lock(mtx);
//     done = true;
//   }
//   cv.notify_all();
// }

// void consumer(int id)
// {
//   while (true)
//   {
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, []
//             { return !buffer.empty() || done; });
//     if (buffer.empty() && done)
//     {
//       break;
//     }
//     {
//       int value = buffer.front();
//       buffer.pop();
//       std::cout << "Consumer {" << id << "}: consumed: " << value << std::endl;
//     }
//   }
// }

void hello()
{
  std::cout << "Hello" << std::endl;
}

void task1()
{
  std::cout << "Task 1" << std::endl;
}

void task2()
{
  std::cout << "Task 2" << std::endl;
}

void task3()
{
  std::cout << "Task 3" << std::endl;
}

int main()
{
  // std::thread prod(producer);
  // std::thread cons1(consumer, 1);
  // std::thread cons2(consumer, 2);
  // std::thread cons3(consumer, 3);
  // prod.join();
  // cons1.join();
  // cons2.join();
  // cons3.join();
  // std::function<void()> task = hello;
  // task();

  buffer.push(task1);
  buffer.push(task2);
  buffer.push(task3);
  while (!buffer.empty())
  {
    std::function<void()> front = buffer.front();
    buffer.pop();
    front();
  }
  return 0;
}