#include <iostream>
#include <thread>
#include <chrono>

void FirstTask()
{
	std::cout << "First Thread Beginning\n" << std::flush; // If output buffer isn't flushed the thread keeps working until it's done. If using endl sometimes it doesn't print new line after switching to another thread.
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "First Thread Working\n" << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << "First Thread End\n" << std::flush;
}

int main()
{
	std::cout << "Main Thread Beginning\n" << std::flush;

	std::thread FirstThread(FirstTask); // Creating a thread that runs FirstTask.
	
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Main Thread Working\n" << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	std::cout << "Main Thread End\n" << std::flush;
	
	FirstThread.join(); // Waits for the FirstTask on FirstThread to finish before continuing with MainThread.
	std::cin.get();
}