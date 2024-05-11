#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
	std::mutex				mtx;
	std::condition_variable cv;
	int						count;

public:
	Semaphore(int count = 0) : count(count)
	{
	}

	void signal()
	{
		std::unique_lock<std::mutex> lock(mtx);
		++count;
		cv.notify_one();
	}

	void wait()
	{
		std::unique_lock<std::mutex> lock(mtx);

		while (count == 0)
		{
			cv.wait(lock);
		}
		--count;
	}
};

#endif // __SEMAPHORE_H__