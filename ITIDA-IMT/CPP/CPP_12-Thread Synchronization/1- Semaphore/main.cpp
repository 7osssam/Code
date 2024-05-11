#include <iostream>
#include <thread>
#include <vector>
#include "semaphore.hpp"

// Shared resource
int sharedResource = 0;

Semaphore sem(1); // Only one thread can access the shared resource at a time

void func(int id)
{
	sem.wait();
	std::cout << "Thread " << id << " is entering the critical section -->\n";

	std::cout << "IN CRITICAL SECTION of" << id << " sharedResource: " << sharedResource << "\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	++sharedResource;

	std::cout << "Thread " << id << " is leaving the critical section <--\n";
	sem.signal();
}

int main()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread(func, i));
	}
	for (auto& thread: threads)
	{
		thread.join();
	}

	std::cout << "Final value of shared resource: " << sharedResource << "\n";

	return 0;
}