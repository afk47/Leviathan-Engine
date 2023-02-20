#pragma once

#include <chrono>

namespace Leviathan {

	class Timer
	{
	public:
		Timer()
		{
			Reset();
		}

		~Timer() 
		{
		}


		void Reset() 
		{
			m_Start = std::chrono::high_resolution_clock::now();
		}

		float GetElapsed() {
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.000000001f;
		}

		float ElapsedMillis()
		{
			return GetElapsed() * 1000.0f;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
		
	};
}


