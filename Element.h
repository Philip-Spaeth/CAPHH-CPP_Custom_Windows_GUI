// Element.h
#pragma once

#include <Windows.h>
#include <string>

class Element {
public:
    virtual ~Element() {}
    virtual void create(HWND parent) = 0;  // Pure virtual function to create the element
    virtual void addID(int newID) = 0;
    virtual void setPos(int x, int y, int width, int height) = 0;
    virtual void setText(const char* text) = 0;
    virtual void setVisibility(bool visible) = 0;
    virtual HWND GetHWND() const = 0;
    virtual std::string getName() const = 0;
};
