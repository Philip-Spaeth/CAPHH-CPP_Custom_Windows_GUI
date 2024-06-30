#include "TextBox.h"
#include <windows.h>

TextBox::TextBox(std::string name, std::wstring* initialText, int x, int y, int width, int height)
    : name(name), text(initialText), x(x), y(y), width(width), height(height), visible(true), hTextBox(nullptr)
{
}

void TextBox::create(HWND parent)
{
    if (hTextBox)
    {
        // If the text box already exists, update its properties
        SetWindowText(hTextBox, text->c_str());
        ShowWindow(hTextBox, visible ? SW_SHOW : SW_HIDE);
        EnableWindow(hTextBox, visible);
        SetWindowPos(hTextBox, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }
    else
    {
        // If the text box does not exist, create it
        hTextBox = CreateWindowEx(
            WS_EX_CLIENTEDGE, L"EDIT", text->c_str(),
            WS_CHILD | (visible ? WS_VISIBLE : 0) | WS_TABSTOP | ES_LEFT | ES_AUTOHSCROLL,
            x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);

        // Set initial text in the text box
        SetWindowText(hTextBox, text->c_str());
    }
}

void TextBox::updateText()
{
    if (hTextBox)
    {
        // Get the length of the text in the text box
        int len = GetWindowTextLength(hTextBox) + 1;
        // Create a temporary buffer to store the text
        wchar_t* buffer = new wchar_t[len];
        // Get the text from the text box
        GetWindowText(hTextBox, buffer, len);
        // Update the text pointer with the new text
        *text = buffer;
        delete[] buffer;  // Free the temporary buffer
    }
}

void TextBox::setPos(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    if (hTextBox)
    {
        SetWindowPos(hTextBox, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    }
}

void TextBox::setText(const char* text)
{
    this->text = new std::wstring(text, text + strlen(text));

    if (hTextBox)
    {
        SetWindowText(hTextBox, this->text->c_str());
    }
}

void TextBox::setVisibility(bool visible)
{
    this->visible = visible;

    if (hTextBox)
    {
        ShowWindow(hTextBox, visible ? SW_SHOW : SW_HIDE);
        EnableWindow(hTextBox, visible);
    }
}

HWND TextBox::GetHWND() const
{
    return hTextBox;
}
