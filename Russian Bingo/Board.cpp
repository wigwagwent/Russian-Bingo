#include "Board.h"
#include "PrintScreen.h"
using namespace std;

int boardCount = 0;

int* Board::calculateBoard() {
    int* line = new int[10];
    int lineCount = 0;
    for (int i = 1; i < 10; i++) {
        line[i] = 0;
    }
    while (lineCount < 5) {

        switch (rand() % 9 + 1) {
        case 1:
            if (line[1] == 0) {
                line[1] = rand() % 9 + 1;
            }
            break;
        case 2:
            if (line[2] == 0) {
                line[2] = rand() % 9 + 11;
            }
            break;
        case 3:
            if (line[3] == 0) {
                line[3] = rand() % 9 + 21;
            }
            break;
        case 4:
            if (line[4] == 0) {
                line[4] = rand() % 9 + 31;
            }
            break;
        case 5:
            if (line[5] == 0) {
                line[5] = rand() % 9 + 41;
            }
            break;
        case 6:
            if (line[6] == 0) {
                line[6] = rand() % 9 + 51;
            }
            break;
        case 7:
            if (line[7] == 0) {
                line[7] = rand() % 9 + 61;
            }
            break;
        case 8:
            if (line[8] == 0) {
                line[8] = rand() % 9 + 71;
            }
            break;
        case 9:
            if (line[9] == 0) {
                line[9] = rand() % 9 + 81;
            }
            break;
        }
        lineCount = 0;
        for (int i = 1; i < 10; i++) {
            if (line[i] > 0) {
                lineCount++;
            }
        }
    }
    return line;
}
void Board::buildBoards() {
    bool matchingNumber1 = true, matchingNumber2 = true;
    while (matchingNumber1 == true || matchingNumber2 == true) {
        matchingNumber1 = false;
        matchingNumber2 = false;
        for (int i = 1; i < 10; i++)
        {
            if (((board1Line1Number[i] == board1Line2Number[i]) || (board1Line1Number[i] == board1Line3Number[i])) && (board1Line1Number[i] != 0)) {
                matchingNumber1 = true;
            }
            if ((board1Line2Number[i] == board1Line3Number[i]) && (board1Line2Number[i] != 0)) {
                matchingNumber2 = true;
            }
        }
        if (matchingNumber1 == true) {
            board1Line1Number = calculateBoard();
        }
        if (matchingNumber2 == true) {
            board1Line2Number = calculateBoard();
        }
    }

    matchingNumber1 = true, matchingNumber2 = true;
    while (matchingNumber1 == true || matchingNumber2 == true) {
        matchingNumber1 = false;
        matchingNumber2 = false;
        for (int i = 1; i < 10; i++)
        {
            if (((board2Line1Number[i] == board2Line2Number[i]) || (board2Line1Number[i] == board2Line3Number[i])) && (board2Line1Number[i] != 0)) {
                matchingNumber1 = true;
            }
            if ((board2Line2Number[i] == board2Line3Number[i]) && (board2Line2Number[i] != 0)) {
                matchingNumber2 = true;
            }
        }
        if (matchingNumber1 == true) {
            board2Line1Number = calculateBoard();
        }
        if (matchingNumber2 == true) {
            board2Line2Number = calculateBoard();
        }
    }

    matchingNumber1 = true, matchingNumber2 = true;
    while (matchingNumber1 == true || matchingNumber2 == true) {
        matchingNumber1 = false;
        matchingNumber2 = false;
        for (int i = 1; i < 10; i++)
        {
            if (((board3Line1Number[i] == board3Line2Number[i]) || (board3Line1Number[i] == board3Line3Number[i])) && (board3Line1Number[i] != 0)) {
                matchingNumber1 = true;
            }
            if ((board3Line2Number[i] == board3Line3Number[i]) && (board3Line2Number[i] != 0)) {
                matchingNumber2 = true;
            }
        }
        if (matchingNumber1 == true) {
            board3Line1Number = calculateBoard();
        }
        if (matchingNumber2 == true) {
            board3Line2Number = calculateBoard();
        }
    }

    matchingNumber1 = true, matchingNumber2 = true;
    while (matchingNumber1 == true || matchingNumber2 == true) {
        matchingNumber1 = false;
        matchingNumber2 = false;
        for (int i = 1; i < 10; i++)
        {
            if (((board4Line1Number[i] == board4Line2Number[i]) || (board4Line1Number[i] == board4Line3Number[i])) && (board4Line1Number[i] != 0)) {
                matchingNumber1 = true;
            }
            if ((board4Line2Number[i] == board4Line3Number[i]) && (board4Line2Number[i] != 0)) {
                matchingNumber2 = true;
            }
        }
        if (matchingNumber1 == true) {
            board4Line1Number = calculateBoard();
        }
        if (matchingNumber2 == true) {
            board4Line2Number = calculateBoard();
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (board1Line1Number[i] < 10) board1Line1Letter[i] = " " + to_string(board1Line1Number[i]);
        else board1Line1Letter[i] = to_string(board1Line1Number[i]);
        if (board1Line2Number[i] < 10) board1Line2Letter[i] = " " + to_string(board1Line2Number[i]);
        else board1Line2Letter[i] = to_string(board1Line2Number[i]);
        if (board1Line3Number[i] < 10) board1Line3Letter[i] = " " + to_string(board1Line3Number[i]);
        else board1Line3Letter[i] = to_string(board1Line3Number[i]);

        if (board2Line1Number[i] < 10) board2Line1Letter[i] = " " + to_string(board2Line1Number[i]);
        else board2Line1Letter[i] = to_string(board2Line1Number[i]);
        if (board2Line2Number[i] < 10) board2Line2Letter[i] = " " + to_string(board2Line2Number[i]);
        else board2Line2Letter[i] = to_string(board2Line2Number[i]);
        if (board2Line3Number[i] < 10) board2Line3Letter[i] = " " + to_string(board2Line3Number[i]);
        else board2Line3Letter[i] = to_string(board2Line3Number[i]);

        if (board3Line1Number[i] < 10) board3Line1Letter[i] = " " + to_string(board3Line1Number[i]);
        else board3Line1Letter[i] = to_string(board3Line1Number[i]);
        if (board3Line2Number[i] < 10) board3Line2Letter[i] = " " + to_string(board3Line2Number[i]);
        else board3Line2Letter[i] = to_string(board3Line2Number[i]);
        if (board3Line3Number[i] < 10) board3Line3Letter[i] = " " + to_string(board3Line3Number[i]);
        else board3Line3Letter[i] = to_string(board3Line3Number[i]);

        if (board4Line1Number[i] < 10) board4Line1Letter[i] = " " + to_string(board4Line1Number[i]);
        else board4Line1Letter[i] = to_string(board4Line1Number[i]);
        if (board4Line2Number[i] < 10) board4Line2Letter[i] = " " + to_string(board4Line2Number[i]);
        else board4Line2Letter[i] = to_string(board4Line2Number[i]);
        if (board4Line3Number[i] < 10) board4Line3Letter[i] = " " + to_string(board4Line3Number[i]);
        else board4Line3Letter[i] = to_string(board4Line3Number[i]);

    }
}
void Board::printBoards(string _boxNumber, int _bank, int _money) {
    string display[22];
    PrintScreen game;
    for (int x = 0; x < 22; x++) {
        display[x] = "";
    }

    game.setScreen(2, "_______________________________________________________________________________________________________________________");
    game.setScreen(3, "______________________________________________Welcome to Russian Lotto_________________________________________________");
    game.setScreen(4, "_______________________________________________________________________________________________________________________");


    display[6] += "     ";
    display[7] += "     ";
    display[8] += "     ";
    display[9] += "     ";
    display[10] += "     ";
    display[11] += "     ";
    display[12] += "     ";
    display[15] += "     ";
    display[16] += "     ";
    display[17] += "     ";
    display[18] += "     ";
    display[19] += "     ";
    display[20] += "     ";
    display[21] += "     ";

    for (int i = 1; i < 10; i++)
    {
        display[7] += " | " + board1Line1Letter[i];
        display[9] += " | " + board1Line2Letter[i];
        display[11] += " | " + board1Line3Letter[i];
        if (boardCount > 1) {
            display[16] += " | " + board2Line1Letter[i];
            display[18] += " | " + board2Line2Letter[i];
            display[20] += " | " + board2Line3Letter[i];
        }
    }


    display[6] += " ----------------------------------------------";
    display[7] += " |";
    display[8] += " ----------------------------------------------";
    display[9] += " |";
    display[10] += " ----------------------------------------------";
    display[11] += " |";
    display[12] += " ----------------------------------------------";

    if (boardCount > 1) {
        display[15] += " ----------------------------------------------";
        display[16] += " |";
        display[17] += " ----------------------------------------------";
        display[18] += " |";
        display[19] += " ----------------------------------------------";
        display[20] += " |";
        display[21] += " ----------------------------------------------";
    }
    if (boardCount > 2) {
        display[6] += "            ";
        display[7] += "            ";
        display[8] += "            ";
        display[9] += "            ";
        display[10] += "            ";
        display[11] += "            ";
        display[12] += "            ";
    }
    if (boardCount > 3) {
        display[15] += "            ";
        display[16] += "            ";
        display[17] += "            ";
        display[18] += "            ";
        display[19] += "            ";
        display[20] += "            ";
        display[21] += "            ";
    }

    for (int i = 1; i < 10; i++)
    {
        if (boardCount > 2) {
            display[7] += " | " + board3Line1Letter[i];
            display[9] += " | " + board3Line2Letter[i];
            display[11] += " | " + board3Line3Letter[i];
        }
        if (boardCount > 3) {
            display[16] += " | " + board4Line1Letter[i];
            display[18] += " | " + board4Line2Letter[i];
            display[20] += " | " + board4Line3Letter[i];
        }
    }
    if (boardCount > 2) {
        display[6] += " ----------------------------------------------";
        display[7] += " |";
        display[8] += " ----------------------------------------------";
        display[9] += " |";
        display[10] += " ----------------------------------------------";
        display[11] += " |";
        display[12] += " ----------------------------------------------";
    }
    if (boardCount > 3) {
        display[15] += " ----------------------------------------------";
        display[16] += " |";
        display[17] += " ----------------------------------------------";
        display[18] += " |";
        display[19] += " ----------------------------------------------";
        display[20] += " |";
        display[21] += " ----------------------------------------------";
    }

    game.setScreen(24, "                                                        ======");
    game.setScreen(25, "                                                        | " + _boxNumber + " |");
    game.setScreen(26, "                                                        ======");
    game.setScreen(27, "Bank: " + to_string(_bank) + "   Your balance: " + to_string(_money));

    for (int x = 6; x < 22; x++) {
        game.setScreen(x, display[x]);
    }
    game.printScreen();
}
bool Board::checkBoards(int _randomNumber, int _deck) {
    if (_deck > 4 || _deck < 0) return 0;
    if (_deck == 1) {
        if (board1Line1Number[_randomNumber / 10 + 1] == _randomNumber) {
            board1Line1Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board1Line2Number[_randomNumber / 10 + 1] == _randomNumber) {
            board1Line2Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board1Line3Number[_randomNumber / 10 + 1] == _randomNumber) {
            board1Line3Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        return 0;
    }
    if (_deck == 2) {
        if (board2Line1Number[_randomNumber / 10 + 1] == _randomNumber) {
            board2Line1Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board2Line2Number[_randomNumber / 10 + 1] == _randomNumber) {
            board2Line2Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board2Line3Number[_randomNumber / 10 + 1] == _randomNumber) {
            board2Line3Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        return 0;
    }
    if (_deck == 3) {
        if (board3Line1Number[_randomNumber / 10 + 1] == _randomNumber) {
            board3Line1Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board3Line2Number[_randomNumber / 10 + 1] == _randomNumber) {
            board3Line2Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board3Line3Number[_randomNumber / 10 + 1] == _randomNumber) {
            board3Line3Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        return 0;
    }
    if (_deck == 4) {
        if (board4Line1Number[_randomNumber / 10 + 1] == _randomNumber) {
            board4Line1Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board4Line2Number[_randomNumber / 10 + 1] == _randomNumber) {
            board4Line2Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        if (board4Line3Number[_randomNumber / 10 + 1] == _randomNumber) {
            board4Line3Letter[_randomNumber / 10 + 1] = "xx";
            return 1;
        }
        return 0;
    }
    return 0;
}
int Board::checkWin(int _selection) {
    int board1Line1Count = 0;
    int board1Line2Count = 0;
    int board1Line3Count = 0;

    int board2Line1Count = 0;
    int board2Line2Count = 0;
    int board2Line3Count = 0;

    int board3Line1Count = 0;
    int board3Line2Count = 0;
    int board3Line3Count = 0;

    int board4Line1Count = 0;
    int board4Line2Count = 0;
    int board4Line3Count = 0;
    for (int i = 1; i < 10; i++)
    {
        if (board1Line1Letter[i] != " 0" && board1Line1Letter[i] != "xx") board1Line1Count++;
        if (board1Line2Letter[i] != " 0" && board1Line2Letter[i] != "xx") board1Line2Count++;
        if (board1Line3Letter[i] != " 0" && board1Line3Letter[i] != "xx") board1Line3Count++;

        if (board2Line1Letter[i] != " 0" && board2Line1Letter[i] != "xx") board2Line1Count++;
        if (board2Line2Letter[i] != " 0" && board2Line2Letter[i] != "xx") board2Line2Count++;
        if (board2Line3Letter[i] != " 0" && board2Line3Letter[i] != "xx") board2Line3Count++;

        if (board3Line1Letter[i] != " 0" && board3Line1Letter[i] != "xx") board3Line1Count++;
        if (board3Line2Letter[i] != " 0" && board3Line2Letter[i] != "xx") board3Line2Count++;
        if (board3Line3Letter[i] != " 0" && board3Line3Letter[i] != "xx") board3Line3Count++;

        if (board4Line1Letter[i] != " 0" && board4Line1Letter[i] != "xx") board4Line1Count++;
        if (board4Line2Letter[i] != " 0" && board4Line2Letter[i] != "xx") board4Line2Count++;
        if (board4Line3Letter[i] != " 0" && board4Line3Letter[i] != "xx") board4Line3Count++;
    }

    if (_selection == 1) {
        if (board1Line1Count < 1 && board1Line2Count < 1 && board1Line3Count < 1) return 3;
        if (board2Line1Count < 1 && board2Line2Count < 1 && board2Line3Count < 1) return 3;
        if (board3Line1Count < 1 && board3Line2Count < 1 && board3Line3Count < 1) return 3;
        if (board4Line1Count < 1 && board4Line2Count < 1 && board4Line3Count < 1) return 3;
        return 0;
    }

    if (_selection == 2) {
        if (board1Line1Count < 1) return 3;
        if (board1Line2Count < 1) return 3;
        if (board1Line3Count < 1) return 3;

        if (board2Line1Count < 1) return 3;
        if (board2Line2Count < 1) return 3;
        if (board2Line3Count < 1) return 3;

        if (board3Line1Count < 1) return 3;
        if (board3Line2Count < 1) return 3;
        if (board3Line3Count < 1) return 3;

        if (board4Line1Count < 1) return 3;
        if (board4Line2Count < 1) return 3;
        if (board4Line3Count < 1) return 3;
        return 0;
    }

    if (_selection == 3) {
        if (board1Line1Count < 1) return 1;
        if (board1Line2Count < 1) return 2;
        if (board1Line3Count < 1) return 3;

        if (board2Line1Count < 1) return 1;
        if (board2Line2Count < 1) return 2;
        if (board2Line3Count < 1) return 3;

        if (board3Line1Count < 1) return 1;
        if (board3Line2Count < 1) return 2;
        if (board3Line3Count < 1) return 3;

        if (board4Line1Count < 1) return 1;
        if (board4Line2Count < 1) return 2;
        if (board4Line3Count < 1) return 3;
        return 0;
    }
    return 0;
}
void Board::reset() {
    boardCount = 0;
    for (int i = 0; i < 10; i++)
    {
        board1Line1Letter[i] = "";
        board1Line1Number[i] = 0;
        board1Line2Letter[i] = "";
        board1Line2Number[i] = 0;
        board1Line3Letter[i] = "";
        board1Line3Number[i] = 0;

        board2Line1Letter[i] = "";
        board2Line1Number[i] = 0;
        board2Line2Letter[i] = "";
        board2Line2Number[i] = 0;
        board2Line3Letter[i] = "";
        board2Line3Number[i] = 0;

        board3Line1Letter[i] = "";
        board3Line1Number[i] = 0;
        board3Line2Letter[i] = "";
        board3Line2Number[i] = 0;
        board3Line3Letter[i] = "";
        board3Line3Number[i] = 0;

        board4Line1Letter[i] = "";
        board4Line1Number[i] = 0;
        board4Line2Letter[i] = "";
        board4Line2Number[i] = 0;
        board4Line3Letter[i] = "";
        board4Line3Number[i] = 0;
    }

}