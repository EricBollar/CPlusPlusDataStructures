#include <iostream>
#include <string>
#include <array>
#include "CFourClass.h"

std::string ConnectFour::tileDraw(tile t) {
    switch(t) {
        case blue : return "🔵";
        case red : return "🔴";
        case white : return "⚪";
    }
}

tile ConnectFour::checkWin() {
    for (int r = 0; r < 6; r++) { // checks all horizontal wins
        for (int c = 0; c <= 3; c++) {
            if (board[r][c] == red && board[r][c + 1] == red && board[r][c + 2] == red && board[r][c + 3] == red) {
                return tile::red;
            } else if (board[r][c] == blue && board[r][c + 1] == blue && board[r][c + 2] == blue && board[r][c + 3] == blue) {
                return tile::blue;
            }
        }
    }

    for (int c = 0; c < 7; c++) { // checks all vertical wins
        for (int r = 0; r <= 2; r++) {
            if (board[r][c] == red && board[r + 1][c] == red && board[r + 2][c] == red && board[r + 3][c] == red) {
                return tile::red;
            } else if (board[r][c] == blue && board[r + 1][c] == blue && board[r + 2][c] == blue && board[r + 3][c] == blue) {
                return tile::blue;
            }
        }
    }

    for (int c = 0; c <= 3; c++) { // checks all diagonal wins
        for (int r = 0; r < 6; r++) {
            if (r <= 2) {
                if (board[r][c] == blue && board[r + 1][c + 1] == blue && board[r + 2][c + 2] == blue && board[r + 3][c + 3] == blue) {
                    return tile::blue;
                } else if (board[r][c] == red && board[r + 1][c + 1] == red && board[r + 2][c + 2] == red && board[r + 3][c + 3] == red) {
                    return tile::red;
                }
            } else {
                if (board[r][c] == blue && board[r - 1][c + 1] == blue && board[r - 2][c + 2] == blue && board[r - 3][c + 3] == blue) {
                    return tile::blue;
                } else if (board[r][c] == red && board[r - 1][c + 1] == red && board[r - 2][c + 2] == red && board[r - 3][c + 3] == red) {
                    return tile::red;
                }
            }
        }
    }

    return tile::white;
}

void ConnectFour::drawBoard() {
    std::cout << std::endl;
    std::cout << " 1  2  3  4  5  6  7" << std::endl;
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 7; c++) {
            std::cout << tileDraw(board[r][c]);
            if (c == 6) {
                std::cout << std::endl;
            } else {
                std::cout << "|";
            }
        }
    }
}

void ConnectFour::resetBoard() {
    for (int c = 0; c < 7; c++) {
        board[c].fill(tile::white);
    }
}

bool ConnectFour::selectColumn(int c, tile turn) {
    if (board[0][c] != white) {
        return false;
    }
    int r = 0;
    while (r < 6) {
        if (board[r][c] != white) {
            board[--r][c] = turn;
            return true;
        } else if (r == 5) {
            board[r][c] = turn;
            return true;
        } else {
            r++;
        }
    }
    std::cout << "error";
    return false;
}