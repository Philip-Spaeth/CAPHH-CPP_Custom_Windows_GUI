#include "Button.h"

void Button::Create(HWND parent) 
{
    CreateWindow(L"BUTTON", text.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        x, y, width, height, parent, (HMENU)(uintptr_t)id, GetModuleHandle(nullptr), nullptr);
}

void Button::SetPos(int x, int y, int width, int height) 
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	SetWindowPos(GetDlgItem(GetParent(GetHWND()), id), nullptr, x, y, width, height, SWP_NOZORDER);
}

void Button::SetText(const char* text) 
{
	this->text = std::wstring(text, text + strlen(text));
	SetWindowText(GetDlgItem(GetParent(GetHWND()), id), this->text.c_str());
	//update the text
	Create(GetParent(GetHWND()));
}

void Button::SetVisible(bool visible) 
{
	ShowWindow(GetDlgItem(GetParent(GetHWND()), id), visible ? SW_SHOW : SW_HIDE);
}

HWND Button::GetHWND() const
{
	return GetDlgItem(GetParent(GetHWND()), id);
}