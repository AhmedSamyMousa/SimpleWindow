#include "Window.h"


int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// Add Window Here
	//          Width  Height  Name Of your Window
	Window  wnd(1366,   768,    "Easy Window");
	wnd.SetFullscreen(false);

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == WM_KEYDOWN)
		{
			switch (msg.wParam)
			{
			case 'F':
				wnd.SetFullscreen(!wnd.isFullscreen);
				break;
			}
		}
	}
	if (gResult == -1)
	{
		return -1;
	}
	return msg.wParam;
}