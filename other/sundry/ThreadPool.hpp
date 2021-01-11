// created by tekky on 2021.1.6.
// ThreadPool.hpp

#ifndef __THREADPOOL_HPP__
#define __THREADPOOL_HPP__

#include <vector>
#include <queue>
#include <condition_variable>
#include <future>
#include <thread>

namespace thl {

class ThreadPool final {
public:
  explicit ThreadPool(std::size_t size);
  ~ThreadPool(); // do not have a virtual destructor, should not derived from this...
  template <typename F, typename... Args>
  auto emplace(F&& f, Args&&... args) ->std::future<typename std::result_of<F(Args...)>::type>;

private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;
  std::mutex mutex_;
  std::condition_variable cv_;
};

ThreadPool::ThreadPool(std::size_t size) {
  for (auto i = 0; i < size; ++i) {
    workers.emplace_back([this] {
			std::function<void()> task;
      while (true) {
        {
				  std::unique_lock<std::mutex> lock(mutex_);
          cv_.wait(lock, [this]() { return !stoped_ && !tasks.empty(); });
          task = std::move(tasks.front());
          tasks.pop();
        }
        task();
			}
    });
  }

}

#endif // __THREADPOOL_HPP__
