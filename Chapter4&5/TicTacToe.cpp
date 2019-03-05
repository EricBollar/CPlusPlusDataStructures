#include <iostream>
#include <string>
#include <array>

std::array<char, 9> boardState;

void drawBoard() {
    std::cout << std::endl;
    std::cout << " " << boardState.at(0) << " ┃ " << boardState.at(1) << " ┃ " << boardState.at(2) << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " " << boardState.at(3) << " ┃ " << boardState.at(4) << " ┃ " << boardState.at(5) << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " " << boardState.at(6) << " ┃ " << boardState.at(7) << " ┃ " << boardState.at(8) << std::endl;
    std::cout << std::endl;
}

bool checkWin() {
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

int main () {
    boardState.fill(' ');
    int selection;

    std::cout << std::endl; // welcoming
    std::cout << " 1 ┃ 2 ┃ 3 " << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " 4 ┃ 5 ┃ 6 " << std::endl;
    std::cout << "———╋———╋———" << std::endl;
    std::cout << " 7 ┃ 8 ┃ 9 " << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    std::cout << "You will be playing as the X player." << std::endl;

    while (!checkWin()) {
        std::cout << "To select your space, please input the number of the tile." << std::endl;
        std::cin >> selection;
        selection--;

        if (boardState.at(selection == ' ')) {
            boardState.at(selection) = 'X';
            drawBoard();
        } else {
            std::cout << "That space is not empty!" << std::endl;
        }
    }

    std::cout << "Winner!" << std::endl;
    std::cout << std::endl;
    return 0;
}

//Art
/*

       o ┃   ┃   
      ———╋———╋———
         ┃ x ┃   
      ———╋———╋———
         ┃   ┃
*/