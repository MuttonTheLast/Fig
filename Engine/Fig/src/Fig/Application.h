#pragma once
#include "Core.h"


namespace Fig
{
    class FIG_API Application
    {
    public:
        Application();
        ~Application();

        void Run();
    };

    // Create Custom App Entry Point Class
    Application* CreateApplication();
}

