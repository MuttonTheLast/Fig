#pragma once

#include "Core.h"
#include <iostream>
#include <string>
namespace Fig
{
	enum class EventType
	{
		None = 0,
		DisplayClose, DisplayResize, DisplayFocus, DisplayLostFocus, DisplayMoved,
		AppTick, AppUpdate, AppRender,
		KeyboardKeyDown, KeyboardKeyUp, KeyboardKey,
		MouseButtonPressed, MouseButtonReleased, MouseButton, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryCore =			BIT(0),
		EventCategoryApp =			BIT(1),
		EventCategoryInput =		BIT(2),
		EventCategoryKeyboard =		BIT(3),
		EventCategoryMouse =		BIT(4),
		EventCategoryMouseButton =	BIT(5),
	};


#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher {
	public:
		

		static void Dispatch(Event& event)
		{
			if (event.IsInCategory(EventCategoryKeyboard))
			{
				std::cout << (int)event.GetEventType();
			}
		}

	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
};