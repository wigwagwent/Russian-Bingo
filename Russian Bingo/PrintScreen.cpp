#include "PrintScreen.h"
#include <iostream>
using namespace std;


void PrintScreen::printScreen(int min, int max)
{
    for (int i = min; i < max; i++)
    {
        cout << "\n" << display[i];
    }
}

std::string PrintScreen::getScreen(int position)
{
    return display[position];
}

void PrintScreen::setScreen(int position, std::string text)
{
    display[position] = text;
}

void PrintScreen::clearScreen()
{
    for (int x = 0; x < 30; x++) {
        display[x] = "";
    }
}

void PrintScreen::blankScreen()
{
    for (int x = 0; x < 35; x++) {
        cout << endl;
    }
}

