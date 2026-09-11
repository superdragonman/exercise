/**
 * @file threadpool.cpp
 * @brief This file contains the implementation of a simple thread pool in C++.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <vector>
#include <stdexcept>
#include <utility>

class ThreadPool
{
public:
  ThreadPool(size_t numThreads)
  {
    for (size_t i = 0; i < numThreads; i++)
    {
      workers.emplace_back([this]
                           { worker(); });
    }
  }
  ~ThreadPool()
  {
    {
      std::unique_lock<std::mutex> lock(queue_mutex);
      stop = true;
    }
    condition.notify_all();
    for (auto &worker : workers)
    {
      if (worker
              .joinable())
      {
        worker.join();
      }
    }
  }
  void enqueue(std::function<void()> task)
  {
    {
      std::lock_guard<std::mutex> lock(queue_mutex);
      if (stop)
      {
        throw std::runtime_error("enqueue on stopped ThreadPool");
      }
      tasks.push(std::move(task));
    }
    condition.notify_one();
  }

private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop = false;

  void worker()
  {
    while (true)
    {
      std::function<void()> task;
      {
        std::unique_lock<std::mutex> lock(queue_mutex);
        condition.wait(lock, [this]
                       { return stop || !tasks.empty(); });
        if (stop && tasks.empty())
          return;
        task = std::move(tasks.front());
        tasks.pop();
      }
      task();
    }
  }
};

void task1()
{
  std::cout << "task1" << std::endl;
}

void task2()
{
  std::cout << "task2" << std::endl;
}

void task3()
{
  std::cout << "task3" << std::endl;
}

int main()
{
  ThreadPool pool(3);
  pool.enqueue(task1);
  pool.enqueue(task2);
  pool.enqueue(task3);
  return 0;
}