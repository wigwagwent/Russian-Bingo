#pragma once
#include <string>
class Board
{
private:
    int** board1Number;
    int** board2Number;
    int** board3Number;
    int** board4Number;

    std::string board1Letter[3][10];
    std::string board2Letter[3][10];
    std::string board3Letter[3][10];
    std::string board4Letter[3][10];

public:
    int boardCount = 0;
    Board();
    int** calculateBoard();
    void buildBoards();
    void printBoards(std::string _boxNumber, int _bank, int _money);
    bool checkBoards(int _randomNumber, int _deck);
    int checkWin(int _selection);
    void reset();
};

