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
    bool visible = true;

public:
    std::string name;
    int id = 0;
    std::function<void()> onClick;

    void addID(int newID) override {id = newID;}

    Button(std::string name, std::wstring text, int x, int y, int width, int height, std::function<void()> onClick)  : name(name), text(text), x(x), y(y), width(width), height(height), onClick(onClick) {}

    void create(HWND parent) override;
    HWND GetHWND() const override;
    std::string getName() const override {return name;}


    std::function<void()> GetOnClickFunction() const {return onClick;}

    void setPos(int x, int y, int width, int height) override;
    void setText(const char* text) override;
    void setVisibility(bool visible) override;
};
