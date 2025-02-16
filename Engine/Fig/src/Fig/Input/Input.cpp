
#include "figpch.h"
#include "Input.h"
namespace Fig
{
	bool Input::m_Keys[256];
	bool Input::m_KeyDown[256];
	bool Input::m_KeyUp[256];

	inline bool const Input::GetKeyDown(int keycode)
	{
		return m_KeyDown[keycode];
	}
	inline bool const Input::GetKeyUp(int keycode)
	{
		return m_KeyUp[keycode];
	}
	inline bool const Input::GetKey(int keycode)
	{
		return m_Keys[keycode];
	}
}
