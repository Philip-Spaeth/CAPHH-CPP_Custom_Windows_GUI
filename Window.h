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
    void addElement(std::shared_ptr<Element> element);
    std::shared_ptr<Element> getElement(std::string name);
    void create(HINSTANCE hInst);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void drawWindow();
    void deleteElement(std::string name);
};
