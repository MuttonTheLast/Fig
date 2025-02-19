#include "figpch.h"
#include "Display.h"
#include "Log/Log.h"


Fig::Display::Display(const DisplayProp& properties)
	: m_Properties(properties)
{
#ifdef SDL_SUPPORTED
	m_Window = SDL_CreateWindow(m_Properties.Title.c_str(), m_Properties.Width, m_Properties.Height, SDL_WINDOW_INPUT_FOCUS);
	if (m_Window == NULL)
	{

		FIG_CORE_ERROR("SDL Window Creation Failed : ");
		FIG_CORE_ERROR(SDL_GetError());
		return;
	}
	FIG_CORE_INFO("SDL Window Created");
#endif 

}

Fig::Display::~Display()
{
}

void Fig::Display::Start()
{
}

void Fig::Display::OnUpdate(const float& deltatime)
{
}

void Fig::Display::Shutdown()
{
}
