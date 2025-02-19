#pragma once
#include "Core.h"
#include "Core/Display.h"


namespace Fig
{
    class FIG_API Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:

        Display* m_Display;
        

    private:
		void CheckEvents();
    /// <summary>
    /// 
    /// </summary>
    public:
		float CurrentRenderFPS() { return m_RenderFPS; }
		float CurrentUpdateRate() { return m_FixedUpdateRate; }
        void SetRenderFPS(const float& fps) { m_RenderFPS = fps; }
        void SetFixedUpdateRate(const float& rate) { m_FixedUpdateRate = rate; }

		float GetFPS() { return m_RenderedFPS; }
		float GetUpdate() { return m_FixedUpdateRate; }
        void SetRefreshTime(const float& time) { m_RefreshTime = time; }
    private:
        virtual void OnStart() = 0;
		virtual void OnLoad() = 0;
        virtual void OnFixedUpdate(const float& deltatime) = 0;
        virtual void AutoUpdate(const float& deltatime) = 0;
        virtual void OnUpdate(const float& deltatime) = 0;
		virtual void OnRender(const float& deltatime) = 0;

    protected:
        bool m_Running = false;
    private:
		float m_FixedUpdateRate = 60.0f;
		float m_FixedUpdateTime = 0.0f;
		float m_RenderFPS = 60.0f;
		float m_RenderTime = 0.0f;

    private:
        short m_RenderedFPS = 0;

        short m_FixedUpdatedRate = 0;
		float m_RefreshTime = 100.0f;
        float m_LastRefTime = 0.0f;
    };

    // Create Custom App Entry Point Class
    Application* CreateApplication();
}

