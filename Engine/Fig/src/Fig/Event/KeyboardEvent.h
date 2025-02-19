#pragma once

#include "Core.h"
#include "Event/Event.h"
#include "Core/KeyCodes.h"
namespace Fig
{
	class KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(KeyCode& keycode)
			: m_KeyCode(keycode) {
		}

		KeyCode m_KeyCode;
	};

	class KeyboardKeyEvent : public KeyEvent
	{
	public:
		KeyboardKeyEvent(KeyCode keycode)
			: KeyEvent(keycode) {
		}
		EVENT_CLASS_TYPE(KeyboardKey)
	};

	class KeyboardKeyDownEvent : public KeyEvent
	{
	public:
		KeyboardKeyDownEvent(KeyCode keycode)
			: KeyEvent(keycode) {
		}
		EVENT_CLASS_TYPE(KeyboardKeyDown)
	};

	class KeyboardKeyUpEvent : public KeyEvent
	{
	public:
		KeyboardKeyUpEvent(KeyCode keycode)
			: KeyEvent(keycode) {
		}
		EVENT_CLASS_TYPE(KeyboardKeyUp)
	};
}