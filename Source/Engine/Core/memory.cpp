#include "memory.h"
#include <iostream>

using namespace std;

umbra::MemoryTracker umbra::g_memoryTracker;

void* operator new (size_t size)
{
	void* p = malloc(size);

	umbra::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete (void* address, size_t size) //takes in the pointer and the size to delete it
{
	umbra::g_memoryTracker.Remove(address, size);
	free(address);
}

namespace umbra
{
	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++; 
	}

	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}

	void MemoryTracker::DisplayInfo()
	{
		cout << "Current bytes allocated: " << m_bytesAllocated << endl;
		cout << "Current number of allocations: " << m_numAllocations << endl;
	}
}