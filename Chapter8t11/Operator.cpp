#include "Operator.h"
#include "CFourClass.h"

void Operator::run(game g) {
    switch (g) {
        case c4 : Operator::CFour(); break;
    }
}

void Operator::CFour() {
    ConnectFour b;
    b.resetBoard();
    b.drawBoard();
    bool playing = true;
    bool blueTurn = true;
    int moves = 0;

    while (b.checkWin() == white && moves < 42) {
        int choice;
        if (blueTurn) {
            std::cout << std::endl;
            std::cout << "It is Blue's Turn! Please choose a column (1-7): ";
            std::cin >> choice;
            choice--;

            bool choosing = true;
            while (choosing) {     
                if (b.selectColumn(choice, blue)) {
                    choosing = false;
                } else {
                    std::cout << std::endl;
                    std::cout << "That column is full! Please choose another column (1-7): ";
                    std::cin >> choice;
                    choice--;
                }
            }

            std::cout << "-------------------------------------------------" << std::endl;
            b.drawBoard();
            blueTurn = false;
        } else {
            std::cout << std::endl;
            std::cout << "It is Red's Turn! Please choose a column (1-7): ";
            std::cin >> choice;
            choice--;
            
            bool choosing = true;
            while (choosing) {     
                if (b.selectColumn(choice, red)) {
                    choosing = false;
                } else {
                    std::cout << "That column is full! Please choose another column (1-7): ";
                    std::cin >> choice;
                    choice--;
                }
            }
            
            std::cout << "-------------------------------------------------" << std::endl;
            b.drawBoard();
            blueTurn = true;
        }
        moves++;
    }

    std::cout << std::endl;
    switch (b.checkWin()) {
        case red : std::cout << "Red Wins!" << std::endl; std::cout << std::endl; break;
        case blue : std::cout << "Blue Wins!" << std::endl; std::cout << std::endl; break;
        case white : std::cout << "Draw!" << std::endl; std::cout << std::endl; break;
    }
}