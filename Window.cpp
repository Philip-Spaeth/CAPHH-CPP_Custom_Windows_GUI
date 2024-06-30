#include "Window.h"
#include "framework.h"
#include "MainWindow.h"
#include "Element.h"
#include "Button.h"
#include "TextBlock.h"
#include "TextBox.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

Window::Window(HINSTANCE hInstance) : hWnd(nullptr)
{
    hnst = hInstance;
    // create the window
    create(hnst);
}

void Window::addElement(std::shared_ptr<Element> element)
{
    elements.push_back(element);

    element->addID(elements.size());
    // Redraw the window
    drawWindow();
}

void Window::deleteElement(std::string name)
{
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i]->getName() == name)
        {
            elements[i]->setVisibility(false);
            elements.erase(elements.begin() + i);
            drawWindow();
            break;
        }
    }
}


std::shared_ptr<Element> Window::getElement(std::string name)
{
    for (auto& element : elements)
    {
        if (element->getName() == name)
        {
			return element;
		}
	}
	return nullptr;
}

void Window::drawWindow()
{
    if (hWnd) 
    {
        // Invalidate the client area to trigger WM_PAINT
        InvalidateRect(hWnd, nullptr, TRUE);
        UpdateWindow(hWnd);

        for (auto& element : elements)
        {
            element->create(hWnd);
        }
        // Don't create the window here, only draw it so that the window is created only once
        ShowWindow(hWnd, SW_SHOW);
        UpdateWindow(hWnd);
    }
}

void Window::create(HINSTANCE hInst) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = Window::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    hWnd = CreateWindowEx(0, CLASS_NAME, L"Sample Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInst, this);

    drawWindow();
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    if (message == WM_CREATE) {
        // Store pointer to Window in window user data
        LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
        Window* pMainWindow = (Window*)pcs->lpCreateParams;
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pMainWindow);
    }
    else {
        Window* pMainWindow = (Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
        if (pMainWindow) {
            switch (message) 
            {
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);

                // Clear the window by filling it with the background color
                FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

                // Add any additional custom drawing code here if needed

                EndPaint(hWnd, &ps);
                break;
            }
            case WM_COMMAND:
                for (auto& element : pMainWindow->elements) {
                    auto button = dynamic_cast<Button*>(element.get());
                    if (button && LOWORD(wParam) == button->id) {
                        auto onClick = button->GetOnClickFunction();
                        if (onClick) {
                            onClick();
                        }
                        return 0;
                    }

                    auto textBox = dynamic_cast<TextBox*>(element.get());
                    if (textBox && HIWORD(wParam) == EN_CHANGE && (HWND)lParam == textBox->GetHandle()) {
                        textBox->updateText();
                        return 0;
                    }
                }
                break;
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            }
        }
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
