#include <iostream>
#include <thread>
#include <chrono>
#include <string>

int iterator = 0;

void FirstTask()
{		
	std::cout << "First Thread Beginning ID: " << std::this_thread::get_id() << "\n" << std::flush; // If output buffer isn't flushed the thread keeps working until it's done. If using endl sometimes it doesn't print new line after switching to another thread.
	for (int i = 0; i < 10; ++i)
	{
		++iterator;
		std::string a = "First Thread Working " + std::to_string(iterator) + "\n";
		std::cout << a << std::flush;
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << "First Thread End ID: " << std::this_thread::get_id() << "\n" << std::flush;
}

int main()
{
	std::cout << "Main Thread Beginning ID: " << std::this_thread::get_id() << "\n" << std::flush;

	std::thread FirstThread(FirstTask); // Creating a thread that runs FirstTask.
	FirstThread.detach(); // Makes the thread run completely independantly without the need to join it.

	for (int i = 0; i < 10; ++i)
	{
		++iterator;
		std::string a = "Main Thread Working " + std::to_string(iterator) + "\n";
		std::cout << a << std::flush;
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << "Main Thread End ID: " << std::this_thread::get_id() << "\n" << std::flush;
	
	//FirstThread.join(); // Waits for the FirstTask on FirstThread to finish before continuing with MainThread.
	std::cin.get();
}