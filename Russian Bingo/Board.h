#pragma once
#include <string>
class Board
{
private:
    int* board1Line1Number = calculateBoard();
    int* board1Line2Number = calculateBoard();
    int* board1Line3Number = calculateBoard();
    int* board2Line1Number = calculateBoard();
    int* board2Line2Number = calculateBoard();
    int* board2Line3Number = calculateBoard();
    int* board3Line1Number = calculateBoard();
    int* board3Line2Number = calculateBoard();
    int* board3Line3Number = calculateBoard();
    int* board4Line1Number = calculateBoard();
    int* board4Line2Number = calculateBoard();
    int* board4Line3Number = calculateBoard();

    std::string board1Line1Letter[10];
    std::string board1Line2Letter[10];
    std::string board1Line3Letter[10];
    std::string board2Line1Letter[10];
    std::string board2Line2Letter[10];
    std::string board2Line3Letter[10];
    std::string board3Line1Letter[10];
    std::string board3Line2Letter[10];
    std::string board3Line3Letter[10];
    std::string board4Line1Letter[10];
    std::string board4Line2Letter[10];
    std::string board4Line3Letter[10];

public:
    int boardCount = 0;

    int* calculateBoard();
    void buildBoards();
    void printBoards(std::string _boxNumber, int _bank, int _money);
    bool checkBoards(int _randomNumber, int _deck);
    int checkWin(int _selection);
    void reset();
};

