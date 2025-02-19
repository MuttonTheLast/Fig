
#include "figpch.h"
#include "Input.h"
namespace Fig
{
	bool Input::m_Keys[512] = { false };
	bool Input::m_KeyDown[512] = { false };
	bool Input::m_KeyUp[512] = { false };

	inline bool const Input::GetKeyDown(const KeyCode& keycode)
	{
		return m_KeyDown[keycode];
	}
	inline bool const Input::GetKeyUp(const KeyCode& keycode)
	{
		return m_KeyUp[keycode];
	}
	inline bool const Input::GetKey(const KeyCode& keycode)
	{
		return m_Keys[keycode];
	}
	inline void Input::SetKeyUp(const KeyCode& keycode)
	{
		m_KeyDown[keycode] = false;
		m_KeyUp[keycode] = true;
		m_Keys[keycode] = false;
	}
	inline void Input::SetKeyDown(const KeyCode& keycode)
	{
		m_KeyDown[keycode] = true;
		m_KeyUp[keycode] = false;
		m_Keys[keycode] = false;
	}
	inline void Input::Update()
	{
		for (unsigned short i = 0; i < 512; i++)
		{
			if (m_KeyDown[i] && !m_KeyUp[i] && !m_Keys[i])
			{
				m_KeyDown[i] = false;
				m_KeyUp[i] = false;
				m_Keys[i] = true;
			}
			else if (m_KeyUp[i])
			{
				m_KeyDown[i] = false;
				m_KeyUp[i] = false;
				m_Keys[i] = false;
			}
		}
	}
}
