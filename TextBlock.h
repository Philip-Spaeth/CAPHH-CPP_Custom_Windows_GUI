#pragma once

#include <Windows.h>
#include <string>
#include "Element.h"

class TextBlock : public Element 
{
private:
	std::wstring text;
	int fontSize;
	COLORREF color;
	HFONT hFont;
	HBRUSH hBrush;
	HDC hdc;
	RECT rect;
	int x, y, width, height;

public: 
	TextBlock(std::wstring text, int x, int y, int fontSize, COLORREF color);

	void Create(HWND parent) override;

	void AddID(int newID) override;

	void SetPos(int x, int y, int width, int height) override;
	void SetText(const char* text) override;
	void SetVisible(bool visible) override;
	HWND GetHWND() const override;
};