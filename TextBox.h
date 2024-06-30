#pragma once

#include "Element.h"
#include <string>

using namespace std;

class TextBox : public Element 
{
private:
    std::wstring* text;  // Zeiger auf den String, der aktualisiert wird
    int x, y, width, height;
    HWND hTextBox;
    bool visible = true;

public:
    std::string name;
    TextBox(std::string name, std::wstring* initialText, int x, int y, int width, int height);

    void create(HWND parent) override;

    void updateText();

    void update() {SetWindowText(hTextBox, text->c_str());}
    std::string getName() const override { return name; }

    void addID(int newID) override {}

    // Getter für das Handle des Textfeldes, falls benötigt
    HWND GetHandle() const {return hTextBox;}

    void setPos(int x, int y, int width, int height) override;
    void setText(const char* text) override;
    void setVisibility(bool visible) override;
    HWND GetHWND() const override;
};
