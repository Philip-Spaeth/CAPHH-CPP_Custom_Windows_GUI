#include "Window.h"
#include "framework.h"
#include "MainWindow.h"
#include "Element.h"
#include "Button.h"
#include "TextBlock.h"
#include "TextBox.h"

Window::Window(HINSTANCE hInstance) : hWnd(nullptr)
{
    hnst = hInstance;
    // Create the window
    Create(hnst);
}

void Window::AddElement(std::shared_ptr<Element> element)
{
    elements.push_back(element);

    element->AddID(elements.size());
    // Redraw the window
    drawWindow(hnst);
}

void Window::drawWindow(HINSTANCE hInst)
{
    if (hWnd) {
        // Only create elements if they are not already created
        for (auto& element : elements)
        {
            element->Create(hWnd);
        }
        // Don't create the window here, only draw it so that the window is created only once
        ShowWindow(hWnd, SW_SHOW);
        UpdateWindow(hWnd);
    }
}

void Window::Create(HINSTANCE hInst) {
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = Window::WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    hWnd = CreateWindowEx(0, CLASS_NAME, L"Sample Window", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInst, this);

    drawWindow(hInst);
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
            switch (message) {
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
                        textBox->UpdateText();
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
