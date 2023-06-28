#include "Core/random.h" //"" for same directory
#include "Core/FileIO.h" 
#include <iostream> //searches the system instead
using namespace std;

int main()
{
	cout << umbra::getFilePath() << endl;


	/*
	umbra::seedRandom((unsigned int)time(nullptr)); //returns system time in seconds starting // () is a cast
	for (int i = 0; i < 10; i++)
	{
		cout << umbra::random(10, 20) << endl;
	}
	*/

}
