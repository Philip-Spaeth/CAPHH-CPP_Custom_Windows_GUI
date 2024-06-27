#include "TextBox.h"


TextBox::TextBox(std::string name, std::wstring* initialText, int x, int y, int width, int height)  : name(name), text(initialText), x(x), y(y), width(width), height(height), hTextBox(nullptr)
{

}

void TextBox::Create(HWND parent)
{
    if (!hTextBox) {
        hTextBox = CreateWindowEx(
            WS_EX_CLIENTEDGE, L"EDIT", text->c_str(),
            WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_LEFT | ES_AUTOHSCROLL,
            x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);

        // Setzen des initialen Textes im Textfeld
        SetWindowText(hTextBox, text->c_str());
    }
}

void TextBox::UpdateText() {
    // Holen Sie die Länge des Textes im Textfeld
    int len = GetWindowTextLength(hTextBox) + 1;
    // Erstellen Sie einen temporären Buffer zum Speichern des Textes
    wchar_t* buffer = new wchar_t[len];
    // Holen Sie den Text aus der Textbox
    GetWindowText(hTextBox, buffer, len);
    // Aktualisieren Sie den Zeiger auf den neuen Text
    *text = buffer;
    delete[] buffer;  // Den temporären Buffer freigeben
}


void TextBox::SetPos(int x, int y, int width, int height)
{
}

void TextBox::SetText(const char* text)
{
}

void TextBox::SetVisible(bool visible)
{
}

HWND TextBox::GetHWND() const
{
    return NULL;
}