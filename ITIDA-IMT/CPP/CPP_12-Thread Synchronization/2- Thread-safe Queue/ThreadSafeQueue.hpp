#ifndef __THREADSAFEQUEUE_H__
#define __THREADSAFEQUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>
#include <cassert>

// Note: Copy constructor and assignment operator are deleted to prevent copying of the queue
// this will cause a compile time error if someone tries to copy the queue object

template <typename T>
class ThreadSafeQueue
{
private:
	std::queue<T>			queue_;
	std::mutex				mutex_;
	std::condition_variable cond_;
	size_t					count_ = 0;

public:
	ThreadSafeQueue() = default;
	ThreadSafeQueue(const ThreadSafeQueue<T>&) = delete;
	ThreadSafeQueue& operator=(const ThreadSafeQueue<T>&) = delete;

	T pop(void)
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		while (queue_.empty())
		{
			cond_.wait(mlock);
		}
		auto item = queue_.front();
		queue_.pop();
		count_--;
		return item;
	}

	void push(const T& item)
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		queue_.push(item);
		count_++;

		mlock.unlock();
		cond_.notify_one();
	}

	bool empty(void)
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		if ((queue_.empty() == true) && (count_ == 0))
		{
			return true;
		}
		return false;
	}

	size_t size(void)
	{
		std::unique_lock<std::mutex> mlock(mutex_);

		try
		{
			if (queue_.size() != count_)
			{
				throw std::runtime_error("Queue size is not equal to count");
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		// we can also return queue_.size() here but we are extra checking if the size of the queue is equal to count
		return count_;
	}
};

#endif // __THREADSAFEQUEUE_H__