#include "Board.h"
#include "PrintScreen.h"
using namespace std;

int boardCount = 0;

Board::Board()
{
    board1Number = calculateBoard();
    board2Number = calculateBoard();
    board3Number = calculateBoard();
    board4Number = calculateBoard();

    buildBoards();
}

int** Board::calculateBoard() {
    int** line = new int*[3];
    int lineCount = 0;
    for (int i = 0; i < 3; i++) {
        line[i] = new int[9];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            line[j][i] = 0;
        }
    }


    for (int i = 0; i < 3; i++)
    {
        while (lineCount < 5) {

            switch (rand() % 9) {
            case 0:
                if (line[i][0] == 0) {
                    line[i][0] = rand() % 9 + 1;
                }
                break;
            case 1:
                if (line[i][1] == 0) {
                    line[i][1] = rand() % 9 + 11;
                }
                break;
            case 2:
                if (line[i][2] == 0) {
                    line[i][2] = rand() % 9 + 21;
                }
                break;
            case 3:
                if (line[i][3] == 0) {
                    line[i][3] = rand() % 9 + 31;
                }
                break;
            case 4:
                if (line[i][4] == 0) {
                    line[i][4] = rand() % 9 + 41;
                }
                break;
            case 5:
                if (line[i][5] == 0) {
                    line[i][5] = rand() % 9 + 51;
                }
                break;
            case 6:
                if (line[i][6] == 0) {
                    line[i][6] = rand() % 9 + 61;
                }
                break;
            case 7:
                if (line[i][7] == 0) {
                    line[i][7] = rand() % 9 + 71;
                }
                break;
            case 8:
                if (line[i][8] == 0) {
                    line[i][8] = rand() % 9 + 81;
                }
                break;
            }
            lineCount = 0;
            for (int j = 0; j < 9; j++) {
                if (line[i][j] > 0) {
                    lineCount++;
                }
            }
        }
        lineCount = 0;
    }
    
    return line;
}
void Board::buildBoards() {
    bool matchingNumber = false;
     do {
         matchingNumber = false;
        for (int i = 0; i < 9; i++)
        {
            if (((board1Number[0][i] == board1Number[1][i]) || (board1Number[0][i] == board1Number[2][i])) && (board1Number[0][i] != 0)) {
                matchingNumber = true;
            }
            if ((board1Number[1][i] == board1Number[2][i]) && (board1Number[1][i] != 0)) {
                matchingNumber = true;
            }
        }
        if (matchingNumber == true) {
            board1Number = calculateBoard();
        }
     } while (matchingNumber == true);

    do {
        matchingNumber = false;
        for (int i = 0; i < 9; i++)
        {
            if (((board2Number[0][i] == board2Number[1][i]) || (board2Number[0][i] == board2Number[2][i])) && (board2Number[0][i] != 0)) {
                matchingNumber = true;
            }
            if ((board2Number[1][i] == board2Number[2][i]) && (board2Number[1][i] != 0)) {
                matchingNumber = true;
            }
        }
        if (matchingNumber == true) {
            board2Number = calculateBoard();
        }
    } while (matchingNumber == true);

    do {
        matchingNumber = false;
        for (int i = 0; i < 9; i++)
        {
            if (((board3Number[0][i] == board3Number[1][i]) || (board3Number[0][i] == board3Number[2][i])) && (board3Number[0][i] != 0)) {
                matchingNumber = true;
            }
            if ((board3Number[1][i] == board3Number[2][i]) && (board3Number[1][i] != 0)) {
                matchingNumber = true;
            }
        }
        if (matchingNumber == true) {
            board3Number = calculateBoard();
        }
    } while (matchingNumber == true);

    do {
        matchingNumber = false;
        for (int i = 0; i < 9; i++)
        {
            if (((board4Number[0][i] == board4Number[1][i]) || (board4Number[0][i] == board4Number[2][i])) && (board4Number[0][i] != 0)) {
                matchingNumber = true;
            }
            if ((board4Number[1][i] == board4Number[2][i]) && (board4Number[1][i] != 0)) {
                matchingNumber = true;
            }
        }
        if (matchingNumber == true) {
            board4Number = calculateBoard();
        }
    } while (matchingNumber == true);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board1Number[j][i] < 10) board1Letter[j][i] = " " + to_string(board1Number[j][i]);
            else board1Letter[j][i] = to_string(board1Number[j][i]);

            if (board2Number[j][i] < 10) board2Letter[j][i] = " " + to_string(board2Number[j][i]);
            else board2Letter[j][i] = to_string(board2Number[j][i]);

            if (board3Number[j][i] < 10) board3Letter[j][i] = " " + to_string(board3Number[j][i]);
            else board3Letter[j][i] = to_string(board3Number[j][i]);

            if (board4Number[j][i] < 10) board4Letter[j][i] = " " + to_string(board4Number[j][i]);
            else board4Letter[j][i] = to_string(board4Number[j][i]);
        }
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

    for (int i = 0; i < 9; i++)
    {
        display[7] += " | " + board1Letter[0][i];
        display[9] += " | " + board1Letter[1][i];
        display[11] += " | " + board1Letter[2][i];
        if (boardCount > 1) {
            display[16] += " | " + board2Letter[0][i];
            display[18] += " | " + board2Letter[1][i];
            display[20] += " | " + board2Letter[2][i];
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

    for (int i = 0; i < 9; i++)
    {
        if (boardCount > 2) {
            display[7] += " | " + board3Letter[0][i];
            display[9] += " | " + board3Letter[1][i];
            display[11] += " | " + board3Letter[2][i];
        }
        if (boardCount > 3) {
            display[16] += " | " + board4Letter[0][i];
            display[18] += " | " + board4Letter[1][i];
            display[20] += " | " + board4Letter[2][i];
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
        for (int i = 0; i < 3; i++)
        {
            if (board1Number[i][_randomNumber / 10] == _randomNumber) {
                board1Letter[i][_randomNumber / 10] = "xx";
                return 1;
            }
        }
        return 0;
    }
    if (_deck == 2) {
        for (int i = 0; i < 3; i++)
        {
            if (board2Number[i][_randomNumber / 10] == _randomNumber) {
                board2Letter[i][_randomNumber / 10] = "xx";
                return 1;
            }
        }
        return 0;
    }
    if (_deck == 3) {
        for (int i = 0; i < 3; i++)
        {
            if (board3Number[i][_randomNumber / 10] == _randomNumber) {
                board3Letter[i][_randomNumber / 10] = "xx";
                return 1;
            }
        }
        return 0;
    }
    if (_deck == 4) {
        for (int i = 0; i < 3; i++)
        {
            if (board4Number[i][_randomNumber / 10] == _randomNumber) {
                board4Letter[i][_randomNumber / 10] = "xx";
                return 1;
            }
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board1Letter[j][i] != " 0" && board1Letter[j][i] != "xx") board1Line1Count++;
            if (board2Letter[j][i] != " 0" && board2Letter[j][i] != "xx") board1Line2Count++;
            if (board3Letter[j][i] != " 0" && board3Letter[j][i] != "xx") board1Line3Count++;
            if (board4Letter[j][i] != " 0" && board4Letter[j][i] != "xx") board2Line1Count++;
        }
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board1Letter[j][i] = "";
            board1Number[j][i] = 0;
            board2Letter[j][i] = "";
            board2Number[j][i] = 0;
            board3Letter[j][i] = "";
            board3Number[j][i] = 0;
            board4Letter[j][i] = "";
            board4Number[j][i] = 0;
        }
    }

}