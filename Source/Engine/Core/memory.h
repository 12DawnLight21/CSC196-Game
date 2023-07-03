#pragma once


namespace umbra
{
	struct MemoryAllocation //like a class but stores a data structure
	{
		void* address;
		size_t size;
		MemoryAllocation* next;
	};

	
	class MemoryTracker //tracks memory that's been allocated
	{
		public:
			void Add(void* address, size_t size); //adds allocation to the list
			void Remove(void* address, size_t size);

			void DisplayInfo();

		private:
			size_t m_bytesAllocated = 0; //member variables have m_ in the class // helps prevent confusion
			size_t m_numAllocations = 0; //number of allocations
 	};
	
	extern MemoryTracker g_memoryTracker;
}
