/**
 * Eric Bollar
 * This runs a simple tic tac toe game where the player can play against another player or against an AI.
 * The AI will always win.
 * Last updated 3/7/19
 * */

#include <iostream>
#include <string> 
#include <array> 

/*

Artwork:

 O ┃   ┃   
———╋———╋———
   ┃ x ┃   
———╋———╋———
   ┃   ┃

*/

enum state {empty, X, O};
enum wld {xW, oW, cont};

void welcomeBoard() { // introduces player to game
    std::cout << std::endl;
    std::cout << " 1 ┃ 2 ┃ 3 " << "     " << std::endl;
    std::cout << "———╋———╋———" << "     " << std::endl;
    std::cout << " 4 ┃ 5 ┃ 6 " << "     " << std::endl;
    std::cout << "———╋———╋———" << "     " << std::endl;
    std::cout << " 7 ┃ 8 ┃ 9 " << "     " << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    std::cout << "You will be playing as the X player." << std::endl;
}

char currSpace(state p) { // returns the correct character given a certain space (for the visuals)
    switch(p) {
        case empty : return ' ';
        case X : return 'X';
        case O : return 'O';
    }
}

void drawBoard(std::array<state, 9> b) { // draws the current boardstate
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Board State          Tile #'s"<< std::endl;
    std::cout << " " << currSpace(b[0]) << " ┃ " << currSpace(b[1]) << " ┃ " << currSpace(b[2]) << "            1 ┃ 2 ┃ 3 " << std::endl;
    std::cout << "———╋———╋———" << "          ———╋———╋———" << std::endl;
    std::cout << " " << currSpace(b.at(3)) << " ┃ " << currSpace(b.at(4)) << " ┃ " << currSpace(b.at(5)) << "            4 ┃ 5 ┃ 6 " << std::endl;
    std::cout << "———╋———╋———" << "          ———╋———╋———" << std::endl;
    std::cout << " " << currSpace(b.at(6)) << " ┃ " << currSpace(b.at(7)) << " ┃ " << currSpace(b.at(8)) << "            7 ┃ 8 ┃ 9 " << std::endl;
    std::cout << std::endl;
}

wld checkState(std::array<state, 9> b) {
    if (b[0] == X && b[1] == X && b[2] == X) {
        return xW;
    } else if (b[0] == O && b[1] == O && b[2] == O) {
        return oW;
    }
    if (b[3] == X && b[4] == X && b[5] == X) {
        return xW;
    } else if (b[3] == O && b[4] == O && b[5] == O) {
        return oW;
    }
    if (b[6] == X && b[7] == X && b[8] == X) {
        return xW;
    } else if (b[6] == O && b[7] == O && b[8] == O) {
        return oW;
    }
    if (b[0] == X && b[3] == X && b[6] == X) {
        return xW;
    } else if (b[0] == O && b[3] == O && b[6] == O) {
        return oW;
    }
    if (b[1] == X && b[4] == X && b[7] == X) {
        return xW;
    } else if (b[1] == O && b[4] == O && b[7] == O) {
        return oW;
    }
    if (b[2] == X && b[5] == X && b[8] == X) {
        return xW;
    } else if (b[2] == O && b[5] == O && b[8] == O) {
        return oW;
    }
    return cont;
}

void playerAI() { // runs a player vs. AI game
    static std::array<state, 9> boardState; // the state of the 9 space board
    boardState.fill(empty); // fills the board with empty spaces
    wld game = cont;
    bool xTurn = true;
    int moves = 0;
    std::string selection;

    std::cout << "You will be playing as the X player. The AI will always win or draw." << std::endl;

    while (game == cont && moves < 9) {
        if (xTurn == true) {
            std::cout << "X Player's turn!" << std::endl;
            std::cout << "To select your space, please input the number of the tile: ";
            std::cin >> selection;
            int space = atoi(selection.c_str()) - 1;

            bool choosing = true;
            while (choosing) {
                if (boardState[space] == empty) {
                    boardState[space] = X;
                    std::cout << std::endl;
                    drawBoard(boardState);
                    choosing = false;
                } else {
                    std::cout << "That space is not empty! Or that is an invalid input!" << std::endl;
                    std::cout << "To select your space, please input the number of the tile: ";
                    std::cin >> selection;
                    space = atoi(selection.c_str()) - 1;
                }
            }
            xTurn = false;
        } else { // AI move
            
        }

        game = checkState(boardState);
        moves++;
    }

    switch (game) {
        case xW : std::cout << "Player Wins!" << std::endl; std::cout << std::endl; break;
        case oW : std::cout << "AI Wins!" << std::endl; std::cout << std::endl; break;
        default : std::cout << "Draw" << std::endl; std::cout << std::endl; break;
    }
}

void pVp() { // runs a player vs. player game
    static std::array<state, 9> boardState; // the state of the 9 space board
    boardState.fill(empty); // fills the board with empty spaces
    wld game = cont;
    bool xTurn = true;
    int moves = 0;
    std::string selection;
    
    while (game == cont && moves < 9) {
        if (xTurn == true) {
            std::cout << "X Player's turn!" << std::endl;
            std::cout << "To select your space, please input the number of the tile: ";
            std::cin >> selection;
            int space = atoi(selection.c_str()) - 1;

            bool choosing = true;
            while (choosing) {
                if (boardState[space] == empty) {
                    boardState[space] = X;
                    std::cout << std::endl;
                    drawBoard(boardState);
                    choosing = false;
                } else {
                    std::cout << "That space is not empty! Or that is an invalid input!" << std::endl;
                    std::cout << "To select your space, please input the number of the tile: ";
                    std::cin >> selection;
                    space = atoi(selection.c_str()) - 1;
                }
            }
            xTurn = false;
        } else {
            std::cout << "O Player's turn!" << std::endl;
            std::cout << "To select your space, please input the number of the tile: ";
            std::cin >> selection;
            int space = atoi(selection.c_str()) - 1;

            bool choosing = true;
            while (choosing) {
                if (boardState[space] == empty) {
                    boardState[space] = O;
                    std::cout << std::endl;
                    drawBoard(boardState);
                    choosing = false;
                } else {
                    std::cout << "That space is not empty! Or that is an invalid input!" << std::endl;
                    std::cout << "To select your space, please input the number of the tile: ";
                    std::cin >> selection;
                    space = atoi(selection.c_str()) - 1;
                }
            }
            xTurn = true;
        }

        game = checkState(boardState);
        moves++;
    }

    switch (game) {
        case xW : std::cout << "X Wins!" << std::endl; std::cout << std::endl; break;
        case oW : std::cout << "O Wins!" << std::endl; std::cout << std::endl; break;
        default : std::cout << "Draw" << std::endl; std::cout << std::endl; break;
    }
}

int main () {
    std::string playChoice;

    std::cout << std::endl;
    std::cout << "Would you like to play against the computer? (Enter 1)" << std::endl;
    std::cout << "Would you like to play against a friend? (Enter 2)" << std::endl;
    std::cin >> playChoice; // receives user input for whether they play against AI or human

    switch (atoi(playChoice.c_str())) // runs pvp or pvAI depending on players choice
    {
        case 1 : welcomeBoard(); playerAI(); break;
        case 2 : welcomeBoard(); pVp(); break;
        default : std::cout << "Please enter a valid input" << std::endl; break;
    }
}