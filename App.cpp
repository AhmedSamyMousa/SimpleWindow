#include "App.h"
#include "Timer.h"

App::App()
    :
    wnd(800,600,"Bimo")
{}

int App::Go()
{

	while (true)
	{
		if (const auto ecode = Window::ProcessMessage())
		{
			return *ecode;
		}		
		DoFrame();
	}

}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);

	wnd.Gfx().EndFrame();
}
