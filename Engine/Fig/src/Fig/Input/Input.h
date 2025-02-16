#pragma once
#include "../Core.h"

namespace Fig
{

	class FIG_API Input
	{
	public:
	
		inline static bool const GetKeyDown(int keycode);
		inline static bool const GetKeyUp(int keycode);
		inline static bool const GetKey(int keycode);


	private:
		
		static bool m_Keys[256]; // 256 possible keys
		static bool m_KeyDown[256]; // 256 possible keys
		static bool m_KeyUp[256]; // 256 possible keys
	};
}

