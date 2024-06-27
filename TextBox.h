#pragma once

#include "Element.h"
#include <string>

using namespace std;

class TextBox : public Element {
private:
    std::wstring* text;  // Zeiger auf den String, der aktualisiert wird
    int x, y, width, height;
    HWND hTextBox;

public:
    TextBox(std::wstring* initialText, int x, int y, int width, int height);

    void Create(HWND parent) override;

    void UpdateText();

    void Update() {SetWindowText(hTextBox, text->c_str());}

    void AddID(int newID) override {}

    // Getter für das Handle des Textfeldes, falls benötigt
    HWND GetHandle() const {return hTextBox;}

    void SetPos(int x, int y, int width, int height) override;
    void SetText(const char* text) override;
    void SetVisible(bool visible) override;
    HWND GetHWND() const override;
};
