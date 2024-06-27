#include "MainWindow.h"
#include "Element.h"
#include "Button.h"
#include "TextBlock.h"
#include "textBox.h"
#include <iostream>

using namespace std;


void MainWindow::Print()
{
    AddElement(std::make_shared<TextBlock>("TextBlock2", L"l", 400, 50, 30, 10));
    GetElement("TextBlock2")->SetText("dsi");
}

MainWindow::MainWindow(HINSTANCE hInstance) : Window(hInstance)
{
    //buttons
    AddElement(std::make_shared<Button>("Button1", L"Button 1", 10, 10, 100, 30, [this]() { Print(); }));
    AddElement(std::make_shared<Button>("Button2", L"ere button", 37, 490, 130, 90, [this]() { Print(); }));

    //Textblocks
    AddElement(std::make_shared<TextBlock>("TextBlock1", L"der dass hier geschrieben hat muss sehr gut sein", 10, 50, 5, 10));

    //TextBox
    AddElement(std::make_shared<TextBox>("TextBox1", & text, 10, 120, 200, 200));
}
