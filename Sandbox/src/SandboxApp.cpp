#include <Fig/Fig.h>


class Sandbox : public Fig::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}



	// Inherited via Application
	void OnStart() override
	{
		SetRefreshTime(1000.0f);
	}

	void OnLoad() override
	{
	}
	float oltime = 1000.0f;
	void OnFixedUpdate(const float& deltatime) override
	{
	}

	void AutoUpdate(const float& deltatime) override
	{
		if (Fig::Input::GetKeyDown(Fig::Key::ESCAPE))
		{
			m_Running = false;
			return;
		}
		if (Fig::Input::GetKeyDown(Fig::Key::A))
		{
			FIG_WARN("New FRAME LIMIT IS : ");
			float newlimit = CurrentRenderFPS() - 1;
			SetRenderFPS(newlimit);
			FIG_WARN(newlimit);

		}
		if (Fig::Input::GetKey(Fig::Key::S))
			FIG_CORE_ERROR("S Holding");
		if (Fig::Input::GetKeyDown(Fig::Key::D))
		{
			FIG_WARN("New FRAME LIMIT IS : ");
			float newlimit = CurrentRenderFPS() + 1;
			SetRenderFPS(newlimit);
			FIG_WARN(newlimit);

		}
		if (Fig::Input::GetKey(Fig::Key::W))
			FIG_CORE_ERROR("W Holding");

		if (oltime <= 0.0f)
		{
			FIG_INFO(GetFPS());
			oltime = 1000;
		}
		oltime -= deltatime;
	}

	void OnUpdate(const float& deltatime) override
	{
	}

	void OnRender(const float& deltatime) override
	{
	}

};


FIG_APPLICATION(Sandbox);