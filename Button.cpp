#include "Button.h"

void Button::create(HWND parent) 
{
    // Check if the button already exists
    HWND buttonHandle = GetDlgItem(parent, id);

    if (buttonHandle)
    {
        SetWindowText(buttonHandle, text.c_str());
        ShowWindow(buttonHandle, visible ? SW_SHOW : SW_HIDE);
        EnableWindow(buttonHandle, visible);
        SetWindowPos(buttonHandle, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }
    else
    {
        // If the button does not exist, create it
        CreateWindow(L"BUTTON", text.c_str(),
            WS_TABSTOP | (visible ? WS_VISIBLE : 0) | WS_CHILD | BS_DEFPUSHBUTTON | (visible ? 0 : WS_DISABLED),
            x, y, width, height, parent, (HMENU)(uintptr_t)id, GetModuleHandle(nullptr), nullptr);
    }

}

void Button::setPos(int x, int y, int width, int height) 
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Button::setText(const char* text) 
{
	this->text = std::wstring(text, text + strlen(text));
}

void Button::setVisibility(bool visible)
{
	this->visible = false;
}

HWND Button::GetHWND() const
{
	return GetDlgItem(GetParent(GetHWND()), id);
}