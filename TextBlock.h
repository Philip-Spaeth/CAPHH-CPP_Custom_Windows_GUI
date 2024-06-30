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
	bool visible = true;


public:
	std::string name;
	TextBlock(std::string name, std::wstring text, int x, int y, int fontSize, COLORREF color);
	std::string getName() const override { return name; }

	void create(HWND parent) override;

	void addID(int newID) override;

	void setPos(int x, int y, int width, int height) override;
	void setText(const char* text) override;
	void setVisibility(bool visible) override;
	HWND GetHWND() const override;
};