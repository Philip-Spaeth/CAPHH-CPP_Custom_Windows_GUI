// Element.h
#pragma once

#include <Windows.h>
#include <string>

class Element {
public:
    virtual ~Element() {}
    virtual void Create(HWND parent) = 0;  // Pure virtual function to create the element
    virtual void AddID(int newID) = 0;
    virtual void SetPos(int x, int y, int width, int height) = 0;
    virtual void SetText(const char* text) = 0;
    virtual void SetVisible(bool visible) = 0;
    virtual HWND GetHWND() const = 0;
    virtual std::string GetName() const = 0;
};
