#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <atomic>

std::atomic<int> iterator = 0; // Atomic Insures that the value is not accessed by multiple threads at the same time.
std::mutex printLock; // Locks a block of code to prevent multiple threads from accessing shared data simultaniously.

void Task(std::string name)
{		
	//std::cout << name << " Thread Beginning ID: " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 100000; ++i)
	{		
		//std::lock_guard<std::mutex> lock(printLock); // Restricts access in scope of this function. Exception safe.
		++iterator;
		//std::cout << name << " Thread Working " << iterator << std::endl;		
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}	
	//std::cout << name << " Thread End ID: " << std::this_thread::get_id() << std::endl;	
}

int main()
{		
	//std::cout << "Main Thread Beginning ID: " << std::this_thread::get_id() << std::endl;
	
	std::thread FirstThread(Task, "First"); // Creating a thread that runs FirstTask.
	std::thread SecondThread(Task, "Second");
	std::thread ThirdThread(Task, "Third");
	
	//FirstThread.detach(); // Makes the thread run completely independantly without the need to join it.
	//SecondThread.detach();

	//std::cout << "Main Thread End ID: " << std::this_thread::get_id() << std::endl;
		
	FirstThread.join(); // Waits for the FirstTask on FirstThread to finish before continuing with MainThread.
	SecondThread.join();
	ThirdThread.join();

	std::cout << iterator << std::endl;
	std::cin.get();
}