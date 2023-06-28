#pragma once
#include <iostream>

//maple calls this kiko in his stuff!
namespace umbra
{
	void seedRandom(unsigned int seed) { srand(seed); } //unsigned = no negative
	int random() { return rand(); }
	int random(unsigned int max) { return rand() % max; } //return 0 - (max - 1)
	int random(unsigned int min, unsigned int max) { return min + random((max - min) + 1); } //returns between min & max (inclusive)
}