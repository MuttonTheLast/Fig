#pragma once
#include "../Core.h"
#include "Core/KeyCodes.h"
namespace Fig
{

	class FIG_API Input
	{
	public:
	
		static bool const GetKeyDown(const KeyCode& keycode);
		static bool const GetKeyUp(const KeyCode& keycode);
		static bool const GetKey(const KeyCode& keycode);

	public:
		static void SetKeyUp(const KeyCode& keycode);
		static void SetKeyDown(const KeyCode& keycode);

		static void Update();
	private:
		
		static bool m_Keys[512]; // 256 possible keys
		static bool m_KeyDown[512]; // 256 possible keys
		static bool m_KeyUp[512]; // 256 possible keys
	};
}

