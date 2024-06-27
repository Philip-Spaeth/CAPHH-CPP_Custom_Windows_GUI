#include "MainWindow.h"
#include "Element.h"
#include "Button.h"
#include "TextBlock.h"
#include "textBox.h"
#include <iostream>

using namespace std;

void MainWindow::Print()
{
    AddElement(std::make_shared<TextBlock>(Text, 400, 50, 30, 10));
}

MainWindow::MainWindow(HINSTANCE hInstance) : Window(hInstance)
{
    //buttons
    AddElement(std::make_shared<Button>(L"Klicken", 10, 10, 100, 30, [this]() { Print(); }));
    AddElement(std::make_shared<Button>(L"Klwrken", 37, 490, 130, 90, [this]() { Print(); }));

    //Textblocks
    AddElement(std::make_shared<TextBlock>(L"Hal der sie geschrieben hat muss sehr gut sein", 10, 50, 5, 10));

    //TextBox
    AddElement(std::make_shared<TextBox>(&text, 10, 100, 200, 200));
}
