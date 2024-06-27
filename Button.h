// Button.h
#pragma once


#include "Element.h"
#include <functional>
#include <string>

using namespace std;

class Button : public Element {
private:
    std::wstring text;
    int x, y, width, height;

public:
    std::string name;
    int id = 0;
    std::function<void()> onClick;

    void AddID(int newID) override {id = newID;}

    Button(std::string name, std::wstring text, int x, int y, int width, int height, std::function<void()> onClick)  : name(name), text(text), x(x), y(y), width(width), height(height), onClick(onClick) {}

    void Create(HWND parent) override;
    HWND GetHWND() const override;
    std::string GetName() const override {return name;}


    std::function<void()> GetOnClickFunction() const {return onClick;}

    void SetPos(int x, int y, int width, int height) override;
    void SetText(const char* text) override;
    void SetVisible(bool visible) override;
};
