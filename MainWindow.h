#pragma once

#include <Windows.h>
#include <string>
#include <functional>
#include "Button.h"
#include "Window.h"
#include <string>

using namespace std;

class MainWindow : public Window
{
public:
	MainWindow(HINSTANCE hInstance);

	std::wstring text = L"dwegh";
	void Print();
};