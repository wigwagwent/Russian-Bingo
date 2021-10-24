#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "board.h"
#include "PrintScreen.h"
using namespace std;


int main()
{
    PrintScreen PrintScreen;
    Board player1;
    Board player2;
    Board player3;

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
        PrintScreen.setScreen(8, "_______________________________________________________________________________________________________________________");
        PrintScreen.setScreen(9, "____________________________________________Welcome to Russian Lotto___________________________________________________");
        PrintScreen.setScreen(10, "_______________________________________________________________________________________________________________________");
        PrintScreen.setScreen(19, "What version do you want to play?");
        PrintScreen.setScreen(20, "1. Regular Lotto - The first player to cover all numbers on the deck wins.");
        PrintScreen.setScreen(21, "2. Short Lotto - The first player to complete a line on the deck wins.");
        PrintScreen.setScreen(22, "3. Three on Three -");
        PrintScreen.setScreen(23, "\tIf the first line is completed everone else doubles their bet into the bank.");
        PrintScreen.setScreen(24, "\tIf the second line is completed then the person gets half the bank.");
        PrintScreen.setScreen(25, "\tIf the third line is completed then the person gets the full bank.");
        PrintScreen.setScreen(26, "4. View Account Details");
        PrintScreen.setScreen(27, "5. Quit");
        PrintScreen.setScreen(29, "Selection: ");
        PrintScreen.printScreen();
        cin >> selection;

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
