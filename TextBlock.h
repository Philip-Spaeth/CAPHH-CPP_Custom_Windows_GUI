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
	std::string name;
	TextBlock(std::string name, std::wstring text, int x, int y, int fontSize, COLORREF color);
	std::string GetName() const override { return name; }

	void Create(HWND parent) override;

	void AddID(int newID) override;

	void SetPos(int x, int y, int width, int height) override;
	void SetText(const char* text) override;
	void SetVisible(bool visible) override;
	HWND GetHWND() const override;
};