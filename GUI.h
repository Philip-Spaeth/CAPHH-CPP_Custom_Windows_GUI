// GUI.h
#pragma once

#include "resource.h"
#include <windows.h>
#include <map>
#include <functional>

// Globale Variablen und Funktionen deklarieren
extern HINSTANCE hInst;
extern std::map<int, std::function<void()>> buttonActions;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void Button1_Click();
void Button2_Click();
