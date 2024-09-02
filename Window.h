#pragma once
#include "MainHeader.h"
#include "WindowsMessageMap.h"

class Window
{
    class WindowClass
    {
    public:
        static const char* GetName() noexcept;
        static HINSTANCE GetInstance() noexcept;
    private:
        WindowClass() noexcept;
        ~WindowClass();
        WindowClass(const WindowClass&) = delete;
        WindowClass& operator = (const WindowClass&) = delete;
        static constexpr const char* wndClassName = "WFW";
        static WindowClass wndClass;
        HINSTANCE hInst;
    };
public:
    Window(int width, int height, const char* name) noexcept;
    ~Window();
    Window(const Window&) = delete;
    Window& operator = (const Window&) = delete;
    void SetFullscreen(bool fullscreen) noexcept;
    bool isFullscreen = false;
private:
    static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
    static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
    LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
private:
    int width;
    int height;
    HWND hWnd;
    WINDOWPLACEMENT wpPrev = { sizeof(wpPrev) };
    WindowsMessageMap msgMap;
};
