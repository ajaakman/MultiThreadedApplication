#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

int iterator = 0;
std::mutex printLock; // Locks a block of code to prevent multiple threads from accessing shared data simultaniously.

void Task(std::string name)
{		
	//std::lock_guard<std::mutex> lock(printLock);
	std::cout << name << " Thread Beginning ID: " << std::this_thread::get_id() << std::endl;
	
	for (int i = 0; i < 10; ++i)
	{
		printLock.lock();
		++iterator;
		std::cout << name << " Thread Working " << iterator << std::endl;
		printLock.unlock();
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}	
	std::cout << name << " Thread End ID: " << std::this_thread::get_id() << std::endl;	
}

int main()
{	
	std::cout << "Main Thread Beginning ID: " << std::this_thread::get_id() << std::endl;
	
	std::thread FirstThread(Task, "First"); // Creating a thread that runs FirstTask.
	FirstThread.detach(); // Makes the thread run completely independantly without the need to join it.
	
	for (int i = 0; i < 10; ++i)
	{
		printLock.lock();
		++iterator;
		std::cout << "Main Thread Working " << std::to_string(iterator) << std::endl;
		printLock.unlock();
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << "Main Thread End ID: " << std::this_thread::get_id() << std::endl;
	
	
	//FirstThread.join(); // Waits for the FirstTask on FirstThread to finish before continuing with MainThread.
	std::cin.get();
}