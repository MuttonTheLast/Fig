#pragma once
#include "Core.h"
#include <string>
#ifdef SDL_SUPPORTED
#include"SDL3/SDL.h"
#endif
namespace Fig
{
	struct DisplayProp
	{
		std::string Title;
		unsigned short Width;
		unsigned short Height;
		bool VSync = false;
		DisplayProp(const std::string& title = "Fig Engine",const unsigned short& width = 1280, const unsigned short& height = 720, const bool& VSync = false)
			: Title(title), Width(width), Height(height), VSync(VSync)
		{
		}
	};

	class Display
	{
	public:

		Display(const DisplayProp& properties);
		~Display();

		void Start();
		void OnUpdate(const float& deltatime);

		void Shutdown();

		const unsigned short& GetWidth() const { return m_Properties.Width; };
		const unsigned short& GetHeight() const { return m_Properties.Height; };

		bool IsVsync() const {};
		void SetVsync(bool enabled) {};
		//using EventCallbackFn = std::function<void(Event&)>;
	private:
		DisplayProp m_Properties;

		const float* m_FixedTime;
		const float* m_RenderTime;
#ifdef SDL_SUPPORTED
	public:
		operator SDL_Window* () const { return m_Window; }
	private:
		SDL_Window* m_Window;
#endif
	};
}
