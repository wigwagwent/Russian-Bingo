#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


void printScreen(string _display[]) {
    cout << _display[0] << endl;
    cout << _display[1] << endl;
    cout << _display[2] << endl;
    cout << _display[3] << endl;
    cout << _display[4] << endl;
    cout << _display[5] << endl;
    cout << _display[6] << endl;
    cout << _display[7] << endl;
    cout << _display[8] << endl;
    cout << _display[9] << endl;
    cout << _display[10] << endl;
    cout << _display[11] << endl;
    cout << _display[12] << endl;
    cout << _display[13] << endl;
    cout << _display[14] << endl;
    cout << _display[15] << endl;
    cout << _display[16] << endl;
    cout << _display[17] << endl;
    cout << _display[18] << endl;
    cout << _display[19] << endl;
    cout << _display[20] << endl;
    cout << _display[21] << endl;
    cout << _display[22] << endl;
    cout << _display[23] << endl;
    cout << _display[24] << endl;
    cout << _display[25] << endl;
    cout << _display[26] << endl;
    cout << _display[27] << endl;
    cout << _display[28] << endl;
    cout << _display[29];
}

class board {
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

    string board1Line1Letter[10];
    string board1Line2Letter[10];
    string board1Line3Letter[10];
    string board2Line1Letter[10];
    string board2Line2Letter[10];
    string board2Line3Letter[10];
    string board3Line1Letter[10];
    string board3Line2Letter[10];
    string board3Line3Letter[10];
    string board4Line1Letter[10];
    string board4Line2Letter[10];
    string board4Line3Letter[10];

public:
    int boardCount = 0;

    int* calculateBoard() {
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
    void buildBoards() {
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
    void printBoards(string _boxNumber, int _bank, int _money) {
        string display[30];
        for (int x = 0; x < 30; x++) {
            display[x] = "";
        }

        display[2] = "_______________________________________________________________________________________________________________________";
        display[3] = "______________________________________________Welcome to Russian Lotto_________________________________________________";
        display[4] = "_______________________________________________________________________________________________________________________";


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

        display[24] = "                                                        ======";
        display[25] = "                                                        | " + _boxNumber + " |";
        display[26] = "                                                        ======";

        display[27] = "Bank: " + to_string(_bank) + "   Your balance: " + to_string(_money);
        
        printScreen(display);
        
    }
    bool checkBoards(int _randomNumber, int _deck) {
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
    int checkWin(int _selection) {
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
    void reset() {
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
};

int main()
{
    board player1;
    board player2;
    board player3;

    string display[30];

    bool usedNumbers[90];
    int selection;

    int bank = 0;
    int money;
    int wonRounds;
    int lostRounds;
    int bet = 0;

    srand(time(0));
    fstream userStats;
    string readLine;

    userStats.open("userData.txt");
    getline(userStats, readLine);
    money = stoi(readLine);
    getline(userStats, readLine);
    wonRounds = stoi(readLine);
    getline(userStats, readLine);
    lostRounds = stoi(readLine);
    userStats.close();


    do {
        for (int x = 0; x < 30; x++) {
            display[x] = "";
        }

        display[8] = "_______________________________________________________________________________________________________________________";
        display[9] = "____________________________________________Welcome to Russian Lotto___________________________________________________";
        display[10] = "_______________________________________________________________________________________________________________________";

        display[19] = "What version do you want to play?";
        display[20] = "1. Regular Lotto - The first player to cover all numbers on the deck wins.";
        display[21] = "2. Short Lotto - The first player to complete a line on the deck wins.";
        display[22] = "3. Three on Three -";
        display[23] = "\tIf the first line is completed everone else doubles their bet into the bank.";
        display[24] = "\tIf the second line is completed then the person gets half the bank.";
        display[25] = "\tIf the third line is completed then the person gets the full bank.";
        display[26] = "4. View Account Details";
        display[27] = "5. Quit";
        display[29] = "Selection: ";
        printScreen(display);
        cin >> selection;

        /*
        for (int x = 0; x < 30; x++) {
            display[x] = "";
        }
        */

        player1.buildBoards();
        player2.buildBoards();
        player3.buildBoards();

        while (player1.boardCount < 1 || player1.boardCount > 4) {
            cout << "How many decks do you want (1-4) at $200 each: ";
            cin >> player1.boardCount;
        }
        do {
            cout << "How much do you want to bet, min is 10, max is your money: ";
            cin >> bet;
        } while (bet < 10 && bet >= money);
        bank = bet * 3 + player1.boardCount * 200 + player2.boardCount * 200 + player3.boardCount * 200;
        money -= (player1.boardCount * 200 + bet);

        player2.boardCount = rand() % player1.boardCount + 1;
        if (player2.boardCount > 4) player2.boardCount = 4;
        player3.boardCount = rand() % player1.boardCount + 1;
        if (player3.boardCount > 4) player3.boardCount = 4;

        int viewPlayers;
        do {  
            cout << "Do you want to view the other players cards, type player number(1,2,3): ";
            cin >> viewPlayers;
            if (viewPlayers == 2) {
                player2.printBoards(" 2", bank, money);
            }
            if (viewPlayers == 3) {
                player3.printBoards(" 3", bank, money);
            }
        } while (viewPlayers == 2 || viewPlayers == 3);

        for (int i = 0; i < 90; i++)
        {
            usedNumbers[i] = false;
        }

        while (player1.checkWin(selection) != 3 && player2.checkWin(selection) != 3 || player3.checkWin(selection) != 3) {
            int randomNumber = rand() % 89 + 1;
            while (usedNumbers[randomNumber]) {
                randomNumber = rand() % 89 + 1;
            }
            usedNumbers[randomNumber] = true;
            string randomNumberLetter;
            
            if (randomNumber < 10) randomNumberLetter = " " + to_string(randomNumber);
            else randomNumberLetter = to_string(randomNumber);
            
            int count;
            player1.printBoards(randomNumberLetter, bank, money);
            cout << "Enter how many times you see the number: ";
            cin >> count;
            if (count <= player1.boardCount && count > 0) {
                for (int i = 0; i < count; i++)
                {
                    int deck;
                    if (player1.boardCount == 1) {
                        deck = 1;
                    }
                    else {
                        cout << "What deck did you see it in: ";
                        cin >> deck;
                    }
                    if (!player1.checkBoards(randomNumber, deck)) {
                        count = 0;
                    }
                    player1.printBoards(randomNumberLetter, bank, money);
                }
                
            }
            for (int i = 1; i <= 4; i++)
            {
                if (rand() % 100 != 1) player2.checkBoards(randomNumber, i);
                if (rand() % 100 != 1) player3.checkBoards(randomNumber, i);
            }

            if (player1.checkWin(selection) == 1) {
                bank += (bet * 2);
            }
            else if (player2.checkWin(selection) == 1 || player3.checkWin(selection) == 1) {
                bank += (bet * 2);
                money -= bet;
            }
            if (player1.checkWin(selection) == 2) {
                bank /= 2;
                money += bank;
            }
            else if (player2.checkWin(selection) == 2 || player3.checkWin(selection) == 2) {
                bank /= 2;
            }
            player1.printBoards(randomNumberLetter, bank, money);

            do {
                cout << "Do you want to view the other players cards, type player number(1,2,3): ";
                cin >> viewPlayers;
                if (viewPlayers == 2) {
                    player2.printBoards(" 2", bank, money);
                }
                if (viewPlayers == 3) {
                    player3.printBoards(" 3", bank, money);
                }
            } while (viewPlayers == 2 || viewPlayers == 3);

        }
        int playerWonCount = 0;

        if (player1.checkWin(selection) == 3) {
            player1.printBoards(" 1", bank, money);
            cout << "You won" << endl;
            playerWonCount++;
            wonRounds++;
        }
        else {
            lostRounds++;
        }
        if (player2.checkWin(selection) == 3) {
            player2.printBoards(" 2", bank, money);
            cout << "Player 2 won" << endl;
            playerWonCount++;
        }
        if (player3.checkWin(selection) == 3) {
            player3.printBoards(" 3", bank, money);
            cout << "Player 3 won" << endl;
            playerWonCount++;
        }
        if (money < 0) {
            money *= 1.08;
            cout << "8% interest because you are negative" << endl;
        }

        money += bank / playerWonCount;
        player1.reset();
        player2.reset();
        player3.reset();

        bank = 0;

        userStats.open("userData.txt");
        userStats << to_string(money) + "\n" + to_string(wonRounds) + "\n" + to_string(lostRounds) + "\n";
        userStats.close();
    } while (selection != 5);
}
