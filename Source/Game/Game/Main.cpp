#include "Core/random.h" //"" for same directory
#include "Core/FileIO.h" 
#include "Core/memory.h"
#include "Core/Time.h"
#include <iostream> //searches the system instead
using namespace std;

//adds literally too much shit at once
/*
void func()
{
	int* p = new int[1000000000]; 
}

void funcs() //will crash your shit with a stack overflow
{
	int i[100000];
	funcs();
}
*/

int main()
{
	//memory time fellas
	umbra::g_memoryTracker.DisplayInfo();
	int* p = new int; //holds the ADDRESS of an int
	umbra::g_memoryTracker.DisplayInfo();
	delete p;
	umbra::g_memoryTracker.DisplayInfo();

	umbra::Time timer;
	for (int i = 0; i < 10000000000000000000; i++) {}
	cout << timer.GetElapsedSeconds() << endl;



	//chrono time, literally	
	//auto start = std::chrono::high_resolution_clock::now(); //auto - figures out the datatype by the code assignment
	//for (int i = 0; i < 10000000000000000000; i++) {}
	//auto end = std::chrono::high_resolution_clock::now();
	//cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl; //<casts> it into microsecodns





	/*
	cout << umbra::getFilePath() << endl;
	umbra::setFilePath("Assets"); //not case sensitive
	cout << umbra::getFilePath() << endl;

	size_t size;
	umbra::getFileSize("game.txt", size);
	cout << size << endl;

	std::string s;
	umbra::readFile("game.txt", s);
	cout << s << endl;
	*/

	// ../ goes back a SINGLE directory, can nagivate the entire directory

	/*
	umbra::seedRandom((unsigned int)time(nullptr)); //returns system time in seconds starting // () is a cast
	for (int i = 0; i < 10; i++)
	{
		cout << umbra::random(10, 20) << endl;
	}
	*/

}
