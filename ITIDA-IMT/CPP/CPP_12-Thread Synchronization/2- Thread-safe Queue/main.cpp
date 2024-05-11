#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#include "ThreadSafeQueue.hpp"

ThreadSafeQueue<int> queue;

void producer()
{
	for (int i = 0; i < 500; ++i)
	{
		queue.push(i);
		//std::cout << "Producer " << std::this_thread::get_id() << " pushed: " << i << "\n";
	}
}

void consumer()
{
	for (int i = 0; i < 500; ++i)
	{
		int value = queue.pop();
		//std::cout << "Consumer " << std::this_thread::get_id() << " popped: " << value << "\n";
	}
}

int main()
{
	std::vector<std::thread> VecOfThreads;

	for (int i = 0; i < 5; ++i)
	{
		VecOfThreads.push_back(std::thread(producer));
		VecOfThreads.push_back(std::thread(consumer));
	}

	for (auto& t: VecOfThreads)
	{
		t.join();
	}

	// to test if it's thread-safe or not, push and pop from the ThreadSafeQueue class has a counter
	// to keep track of the number of elements in the queue and the size of the queue
	// if the queue is thread-safe, the size of the queue should be 0 and the queue should be empty
	assert(queue.empty() && queue.size() == 0);

	std::cout << "\nThis queue is thread-safe\n";

	return 0;
}