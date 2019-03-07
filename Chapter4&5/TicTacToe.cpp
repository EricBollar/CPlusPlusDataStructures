/**
 * Eric Bollar
 * This runs a simple tic tac toe game where the player can play against another play or against an AI.
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
enum wld {xW, oW, draw, cont};

void welcomeBoard() { // introduces player to game
    std::cout << std::endl;
    std::cout << " 1 ┃ 2 ┃ 3 " << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " 4 ┃ 5 ┃ 6 " << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " 7 ┃ 8 ┃ 9 " << std::endl;
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
    std::cout << std::endl;
    std::cout << " " << currSpace(b[0]) << " ┃ " << currSpace(b[1]) << " ┃ " << currSpace(b[2]) << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " " << currSpace(b.at(3)) << " ┃ " << currSpace(b.at(4)) << " ┃ " << currSpace(b.at(5)) << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " " << currSpace(b.at(6)) << " ┃ " << currSpace(b.at(7)) << " ┃ " << currSpace(b.at(8)) << std::endl;
    std::cout << std::endl;
}

wld checkState(std::array<state, 9> b) {
    if (b[0] == state::X && b[1] == state::X && b[2] == state::X) {
        return wld::xW;
    } else if (b[0] == state::O && b[1] == state::O && b[2] == state::O) {
        return wld::oW;
    }
    if (b[3] == state::X && b[4] == state::X && b[5] == state::X) {
        return wld::xW;
    } else if (b[3] == state::O && b[4] == state::O && b[5] == state::O) {
        return wld::oW;
    }
    if (b[6] == state::X && b[7] == state::X && b[8] == state::X) {
        return wld::xW;
    } else if (b[6] == state::O && b[7] == state::O && b[8] == state::O) {
        return wld::oW;
    }
    if (b[0] == state::X && b[3] == state::X && b[6] == state::X) {
        return wld::xW;
    } else if (b[0] == state::O && b[3] == state::O && b[6] == state::O) {
        return wld::oW;
    }
    if (b[1] == state::X && b[4] == state::X && b[7] == state::X) {
        return wld::xW;
    } else if (b[1] == state::O && b[4] == state::O && b[7] == state::O) {
        return wld::oW;
    }
    if (b[2] == state::X && b[5] == state::X && b[8] == state::X) {
        return wld::xW;
    } else if (b[2] == state::O && b[5] == state::O && b[8] == state::O) {
        return wld::oW;
    }
    return wld::cont;
}

void playerAI() { // runs a player vs. AI game
    wld game = wld::cont;
    bool playerTurn = true;

    while (game == wld::cont) {

    }
}

void pVp() { // runs a player vs. player game
    static std::array<state, 9> boardState; // the state of the 9 space board
    boardState.fill(state::empty); // fills the board with empty spaces
    wld game = wld::cont;
    bool xTurn = true;
    int moves = 0;
    
    while (game == wld::cont && moves < 9) {
        if (xTurn == true) {

        } else {

        }
        game = checkState(boardState);
        moves++;
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









/*
std::array<char, 9> boardState; // global scope spooky. must fix


void welcomeBoard() {
    std::cout << std::endl; // welcoming
    std::cout << " 1 ┃ 2 ┃ 3 " << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " 4 ┃ 5 ┃ 6 " << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " 7 ┃ 8 ┃ 9 " << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    std::cout << "You will be playing as the X player." << std::endl;
}

void drawBoard() {
    std::cout << std::endl; // draws the board with current state
    std::cout << " " << boardState.at(0) << " ┃ " << boardState.at(1) << " ┃ " << boardState.at(2) << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " " << boardState.at(3) << " ┃ " << boardState.at(4) << " ┃ " << boardState.at(5) << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " " << boardState.at(6) << " ┃ " << boardState.at(7) << " ┃ " << boardState.at(8) << std::endl;
    std::cout << std::endl;
}

bool checkPlayerWin() { // need to make prettier
    if (boardState.at(0) == 'X') {
        if (boardState.at(1) == 'X' && boardState.at(2) == 'X') {
            return true;
        }
        if (boardState.at(3) == 'X' && boardState.at(6) == 'X') {
            return true;
        }
    }
    if (boardState.at(2) == 'X') {
        if (boardState.at(0) == 'X' && boardState.at(1) == 'X') {
            return true;
        }
        if (boardState.at(5) == 'X' && boardState.at(8) == 'X') {
            return true;
        }
    }
    if (boardState.at(4) == 'X') {
        if (boardState.at(0) == 'X' && boardState.at(8) == 'X') {
            return true;
        }
        if (boardState.at(2) == 'X' && boardState.at(6) == 'X') {
            return true;
        }
        if (boardState.at(1) == 'X' && boardState.at(7) == 'X') {
            return true;
        }
        if (boardState.at(3) == 'X' && boardState.at(5) == 'X') {
            return true;
        }
    }
    if (boardState.at(8) == 'X') {
        if (boardState.at(6) == 'X' && boardState.at(7) == 'X') {
            return true;
        }
    }
    return false;
}

bool checkAIWin() { // need to make prettier
    if (boardState.at(0) == 'O') {
        if (boardState.at(1) == 'O' && boardState.at(2) == 'O') {
            return true;
        }
        if (boardState.at(3) == 'O' && boardState.at(6) == 'O') {
            return true;
        }
    }
    if (boardState.at(2) == 'O') {
        if (boardState.at(0) == 'O' && boardState.at(1) == 'O') {
            return true;
        }
        if (boardState.at(5) == 'O' && boardState.at(8) == 'O') {
            return true;
        }
    }
    if (boardState.at(4) == 'O') {
        if (boardState.at(0) == 'O' && boardState.at(8) == 'O') {
            return true;
        }
        if (boardState.at(2) == 'O' && boardState.at(6) == 'O') {
            return true;
        }
        if (boardState.at(1) == 'O' && boardState.at(7) == 'O') {
            return true;
        }
        if (boardState.at(3) == 'O' && boardState.at(5) == 'O') {
            return true;
        }
    }
    if (boardState.at(8) == 'O') {
        if (boardState.at(6) == 'O' && boardState.at(7) == 'O') {
            return true;
        }
    }
    return false;
}

int main () {
    boardState.fill(' ');
    welcomeBoard();
    int selection;
    int fill = 0;

    while(true) {
        std::cout << "To select your space, please input the number of the tile." << std::endl;
        std::cin >> selection;
        selection--;

        if (boardState.at(selection) == ' ') {
            boardState.at(selection) = 'X';
            std::cout << std::endl;
            std::cout << "Your move: ";
            drawBoard();
            fill++;
        } else {
            std::cout << "That space is not empty!" << std::endl;
        }
        
        // random ai move
        int aiMove = rand() % 8;
        while (true) {
            if (boardState.at(aiMove) == ' ') {
                boardState.at(aiMove) = 'O';
                std::cout << "The computer responds: ";
                drawBoard();
                fill++;
                break;
            } else {
                aiMove = rand() % 8;
            }
        }

        // check game state
        if (checkAIWin()) {
            std::cout << "AI wins." << std::endl;
            break;
        } else if (checkPlayerWin()) {
            std::cout << "Player wins." << std::endl;
            break;
        } else if (fill == 9) {
            std::cout << "Draw." << std::endl;
            break;
        }
    }
    

    std::cout << "end";
}

//Art
/*

       o ┃   ┃   
      ———╋———╋———
         ┃ x ┃   
      ———╋———╋———
         ┃   ┃
*/