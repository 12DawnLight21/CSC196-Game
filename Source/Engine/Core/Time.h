#pragma once
#include <chrono>

namespace umbra
{
	class Time
	{
	private:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_rep = clock::rep;

	public:
		Time() : 
			m_startTime{ clock::now() },
			m_frameTime{ clock::now() }
		{}

		void Tick();
		void Reset() { m_startTime = clock::now(); }

		clock_rep GetElapsedNanoseconds();
		clock_rep GetElapsedMicroseconds();
		clock_rep GetElapsedMilliseconds();
		float GetElapsedSeconds();

		float GetTime() const { return m_time; };
		float GetDeltaTime() const { return m_deltaTime; };

	private:
		float m_time = 1.0f;
		float m_deltaTime = 1.0f;

		clock::time_point m_startTime;
		clock::time_point m_frameTime;
	};

	extern Time g_time;
}
