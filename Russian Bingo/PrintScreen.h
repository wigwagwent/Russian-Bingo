#pragma once
#include <string>

class PrintScreen
{
private:
    std::string display[30];
public:
    void printScreen(int min = 0, int max = 30);
    std::string getScreen(int position);
    void setScreen(int position, std::string text);
    void clearScreen();
    void blankScreen();
};

