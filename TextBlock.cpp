#include "TextBlock.h"

TextBlock::TextBlock(std::string name, std::wstring text, int x, int y, int fontSize, COLORREF color) : name(name), text(text), x(x), y(y), fontSize(fontSize), color(color)
{
}

void TextBlock::create(HWND parent)
{
	if (visible == true)
	{
		width = text.length() * fontSize * 0.5; // Schätzweise halbe Zeichenbreite für typische Schriftarten
		height = (int)(fontSize * 1.5); // Höhe aufgrund der Schriftgröße mit etwas Puffer

		hdc = GetDC(parent);
		// Erstellen und Auswählen der Schriftart
		hFont = CreateFont(fontSize, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
		SelectObject(hdc, hFont);
		// Textfarbe und Transparenzmodus setzen
		SetTextColor(hdc, color);
		SetBkMode(hdc, TRANSPARENT);
		// Berechnen des Zeichenbereichs für den Text
		rect = { x, y, x + width, y + height };
		// Text linksbündig und an der oberen Kante des Bereichs zeichnen
		DrawText(hdc, text.c_str(), -1, &rect, DT_LEFT | DT_TOP | DT_SINGLELINE);
		// Aufräumen
		DeleteObject(hFont);
		ReleaseDC(parent, hdc);
	}
}

void TextBlock::addID(int newID)
{
}

void TextBlock::setPos(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void TextBlock::setText(const char* text)
{
	this->text = std::wstring(text, text + strlen(text));
}

void TextBlock::setVisibility(bool visible)
{
	this->visible = visible;
}

HWND TextBlock::GetHWND() const
{
	return NULL;
}