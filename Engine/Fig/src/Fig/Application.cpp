#include "figpch.h"
#include "Application.h"
#include "Log/Log.h"
#include "Input/Input.h"
#include "Event/KeyboardEvent.h"

namespace Fig
{
	Application::Application()
		:m_Display(nullptr)
	{
		
	}
	Application::~Application()
	{
		m_Display->Shutdown();
		delete m_Display;
	}

	// an event to check what happening about window based on highest render or fixedupdate rate
	void Application::CheckEvents()
	{
		const bool& baseOnRenderer = m_RenderFPS > m_FixedUpdateRate;
		const float& updateTime = baseOnRenderer? m_RenderTime : m_FixedUpdateTime;
		const float& updateRate = baseOnRenderer? m_RenderFPS : m_FixedUpdateRate;
		

		if (updateTime < 1000.0f / updateRate)
			return;
		Fig::Input::Update();
#ifdef SDL_SUPPORTED
		SDL_Event event;
		while (SDL_PollEvent(&event)) {  
			switch (event.type)
			{
			case SDL_EVENT_KEY_DOWN:
				if (!event.key.repeat) {
					Fig::Input::SetKeyDown(event.key.key);
				}
				break;
			case SDL_EVENT_KEY_UP:
				if (!event.key.repeat) {
					Fig::Input::SetKeyUp(event.key.key);
				}
				break;
			default:
				break;
			}
		}
#endif // SDL_SUPPORTED
		AutoUpdate(updateTime);
	}

	void Application::Run()
	{

		m_Display = new Display({});
		///////////////////
		using clock = std::chrono::steady_clock;

		OnStart();
		OnLoad();
		m_Running = true;
		auto LastClock = clock::now();
		float ClockCount = 0.0f;
		short rendered = 0;
		short fixedupdated = 0;
		while (m_Running)
		{
			// check clock and then check frames every 0.01ms
			auto CurrentTime = clock::now();
			float ClockOffset = std::chrono::duration<float, std::milli>(CurrentTime - LastClock).count();
			LastClock = CurrentTime;
			ClockCount += ClockOffset;
			if (ClockCount <= 0.01f)
			{
				continue;
			}
			// add clock countt to do fps check , update, fixedupdate, render
			m_RenderTime += ClockCount;
			m_FixedUpdateTime += ClockCount;
			m_LastRefTime += ClockCount;

			//
			CheckEvents();
			// Update based on given Frame
			if (m_FixedUpdateTime >= 1000.0f / m_FixedUpdateRate)
			{
				OnFixedUpdate(m_FixedUpdateTime);
				fixedupdated++;
				m_FixedUpdateTime = 0.0f;
			}
			if (m_RenderTime >= 1000.0f / m_RenderFPS)
			{
				m_Display->OnUpdate(m_RenderTime);
				OnUpdate(m_RenderTime);
				OnRender(m_RenderTime);
				rendered = rendered + 1;
				m_RenderTime = 0.0f;
			}
			if (m_LastRefTime >= m_RefreshTime)
			{
				m_RenderedFPS = rendered * (1000.0f / m_RefreshTime);
				m_FixedUpdatedRate = fixedupdated * (1000.0f / m_RefreshTime);
				rendered = 0;
				fixedupdated = 0;
				m_LastRefTime = 0.0f;
			}

			ClockCount = 0.0f;
		}
	}

}