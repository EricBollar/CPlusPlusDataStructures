#include <iostream>
#include <string>
#include <array>


/**
 * Artwork:
 * 
 * ⚪|⚪|⚪|⚪|⚪|⚪|⚪
 * ⚪|⚪|⚪|⚪|⚪|⚪|⚪
 * ⚪|⚪|⚪|⚪|🔴|⚪|⚪
 * ⚪|⚪|⚪|🔵|🔴|⚪|⚪
 * ⚪|⚪|⚪|🔵|🔴|⚪|⚪
 * ⚪|⚪|🔵|🔵|🔴|⚪|⚪
 * 
 * */

enum tile {blue, red, white};

class ConnectFour {
    std::array<std::array<tile, 7>, 6> board; // board[row][column]

    public:
        std::string tileDraw(tile t) {
            switch(t) {
                case blue : return "🔵";
                case red : return "🔴";
                case white : return "⚪";
            }
        }

        tile checkWin() {
            for (int r = 0; r < 6; r++) { // checks all horizontal wins
                for (int c = 0; c <= 3; c++) {
                    if (board[r][c] == red && board[r][c + 1] == red && board[r][c + 2] == red && board[r][c + 3] == red) {
                        return red;
                    } else if (board[r][c] == blue && board[r][c + 1] == blue && board[r][c + 2] == blue && board[r][c + 3] == blue) {
                        return blue;
                    }
                }
            }

            for (int c = 0; c < 7; c++) { // checks all vertical wins
                for (int r = 0; r <= 2; r++) {
                    if (board[r][c] == red && board[r + 1][c] == red && board[r + 2][c] == red && board[r + 3][c] == red) {
                        return red;
                    } else if (board[r][c] == blue && board[r + 1][c] == blue && board[r + 2][c] == blue && board[r + 3][c] == blue) {
                        return blue;
                    }
                }
            }

            for (int c = 0; c <= 3; c++) { // checks all diagonal wins
                for (int r = 0; r < 6; r++) {
                    if (r <= 2) {
                        if (board[r][c] == blue && board[r + 1][c + 1] == blue && board[r + 2][c + 2] == blue && board[r + 3][c + 3] == blue) {
                            return blue;
                        } else if (board[r][c] == red && board[r + 1][c + 1] == red && board[r + 2][c + 2] == red && board[r + 3][c + 3] == red) {
                            return red;
                        }
                    } else {
                        if (board[r][c] == blue && board[r - 1][c + 1] == blue && board[r - 2][c + 2] == blue && board[r - 3][c + 3] == blue) {
                            return blue;
                        } else if (board[r][c] == red && board[r - 1][c + 1] == red && board[r - 2][c + 2] == red && board[r - 3][c + 3] == red) {
                            return red;
                        }
                    }
                }
            }

            return white;
        }

        void drawBoard() {
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

        void resetBoard() {
            for (int c = 0; c < 7; c++) {
                board[c].fill(white);
            }
        }

        bool selectColumn(int c, tile turn) {
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
};

int main () {
    ConnectFour b;
    b.resetBoard();
    b.drawBoard();
    bool playing = true;
    bool blueTurn = true;
    int moves = 0;

    while (b.checkWin() == white && moves < 42) {
        int choice;
        if (blueTurn) {
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

            b.drawBoard();
            blueTurn = false;
        } else {
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