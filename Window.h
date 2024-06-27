// Window.h
#pragma once

#include <Windows.h>
#include <vector>
#include <memory>
#include "Element.h"
#include "Button.h"

class Window {
protected:
    HWND hWnd;
    HINSTANCE hnst;
    std::vector<std::shared_ptr<Element>> elements;


public:
    Window(HINSTANCE hInstance);
    void AddElement(std::shared_ptr<Element> element);
    void Create(HINSTANCE hInst);
    void Update();
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void drawWindow(HINSTANCE hInst);
};
