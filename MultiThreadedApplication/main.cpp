#include <iostream>
#include <thread>

void FirstTask()
{
	std::cout << "First Thread Beginning\n" << std::flush;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "First Thread Working\n" << std::flush;
	}
	std::cout << "First Thread End\n" << std::flush;
}

int main()
{
	std::cout << "Main Thread Beginning\n" << std::flush;

	std::thread FirstThread(FirstTask); // Creating a thread that runs FirstTask.
	
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Main Thread Working\n" << std::flush;
	}

	std::cout << "Main Thread End\n" << std::flush;
	
	FirstThread.join(); // Waits for the FirstTask on FirstThread to finish before continuing with MainThread.
	std::cin.get();
}