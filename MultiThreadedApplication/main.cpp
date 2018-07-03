#include <iostream>
#include <thread>
#include <chrono>
#include <string>

int iterator = 0;

void FirstTask(std::string name)
{		
	std::cout << name << " Thread Beginning ID: " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		++iterator;
		std::cout << name << " Thread Working " << iterator << std::endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << name << " Thread End ID: " << std::this_thread::get_id() << std::endl;
}

int main()
{
	std::cout << "Main Thread Beginning ID: " << std::this_thread::get_id() << std::endl;

	std::thread FirstThread(FirstTask, "First"); // Creating a thread that runs FirstTask.
	FirstThread.detach(); // Makes the thread run completely independantly without the need to join it.

	for (int i = 0; i < 10; ++i)
	{
		++iterator;
		std::cout << "Main Thread Working " << std::to_string(iterator) << std::endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << "Main Thread End ID: " << std::this_thread::get_id() << std::endl;
	
	//FirstThread.join(); // Waits for the FirstTask on FirstThread to finish before continuing with MainThread.
	std::cin.get();
}