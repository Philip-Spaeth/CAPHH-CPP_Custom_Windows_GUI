#include "TextBlock.h"

TextBlock::TextBlock(std::wstring text, int x, int y, int fontSize, COLORREF color)	: text(text), x(x), y(y), fontSize(fontSize), color(color)
{
	// set the heigth and width of the text block according to the text and font size
	width = text.length() * fontSize * 0.5; // Schätzweise halbe Zeichenbreite für typische Schriftarten
	height = (int)(fontSize * 1.5); // Höhe aufgrund der Schriftgröße mit etwas Puffer
}

void TextBlock::Create(HWND parent)
{
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

void TextBlock::AddID(int newID)
{
}

void TextBlock::SetPos(int x, int y, int width, int height)
{
}

void TextBlock::SetText(const char* text)
{
	this->text = std::wstring(text, text + strlen(text));
}

void TextBlock::SetVisible(bool visible)
{
}

HWND TextBlock::GetHWND() const
{
	return NULL;
}