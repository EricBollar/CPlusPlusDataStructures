/**
 * Eric Bollar
 * This runs a simple tic tac toe game where the player can play against another player or against an AI.
 * The AI will always win.
 * Last updated 3/8/19
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

enum state {empty, X, O}; // state of each space
enum wld {xW, oW, cont}; // win lose continue (gamestate)

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

wld checkState(std::array<state, 9> b) { // checks every possible win state for X and O
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
    if (b[0] == X && b[4] == X && b[8] == X) {
        return xW;
    } else if (b[0] == O && b[4] == O && b[8] == O) {
        return oW;
    }
    if (b[2] == X && b[4] == X && b[6] == X) {
        return xW;
    } else if (b[2] == O && b[4] == O && b[6] == O) {
        return oW;
    }
    return cont;
}

int chooseSpace(std::array<state, 9> b) { // returns best space for the AI to play - tries to block player 
    // tries to win
    if (b[4] == empty) {
        return 4;
    }
    if (b[0] == O && b[1] == O && b[2] == empty) {
        return 2;
    } else if (b[1] == O && b[2] == O && b[0] == empty) {
        return 0;
    } else if (b[0] == O && b[2] == O && b[1] == empty) {
        return 1;
    } else if (b[3] == O && b[4] == O && b[5] == empty) {
        return 5;
    } else if (b[4] == O && b[5] == O && b[3] == empty) {
        return 3;
    } else if (b[3] == O && b[5] == O && b[4] == empty) {
        return 4;
    } else if (b[6] == O && b[7] == O && b[8] == empty) {
        return 8;
    } else if (b[7] == O && b[8] == O && b[6] == empty) {
        return 6;
    } else if (b[6] == O && b[8] == O && b[7] == empty) {
        return 7;
    } else if (b[0] == O && b[3] == O && b[6] == empty) {
        return 6;
    } else if (b[3] == O && b[6] == O && b[0] == empty) {
        return 0;
    } else if (b[0] == O && b[6] == O && b[3] == empty) {
        return 3;
    } else if (b[1] == O && b[4] == O && b[7] == empty) {
        return 7;
    } else if (b[4] == O && b[7] == O && b[1] == empty) {
        return 1;
    } else if (b[1] == O && b[7] == O && b[4] == empty) {
        return 4;
    } else if (b[2] == O && b[5] == O && b[8] == empty) {
        return 8;
    } else if (b[5] == O && b[8] == O && b[2] == empty) {
        return 2;
    } else if (b[2] == O && b[8] == O && b[5] == empty) {
        return 5;
    } else if (b[0] == O && b[4] == O && b[8] == empty) {
        return 8;
    } else if (b[4] == O && b[8] == O && b[0] == empty) {
        return 0;
    } else if (b[0] == O && b[8] == O && b[4] == empty) {
        return 4;
    } else if (b[2] == O && b[4] == O && b[6] == empty) {
        return 6;
    } else if (b[4] == O && b[6] == O && b[2] == empty) {
        return 2;
    } else if (b[2] == O && b[6] == O && b[4] == empty) {
        return 4;
    }

    // if cannot win, tries to block player
    if (b[4] == empty) {
        return 4;
    }
    if (b[0] == X && b[1] == X && b[2] == empty) {
        return 2;
    } else if (b[1] == X && b[2] == X && b[0] == empty) {
        return 0;
    } else if (b[0] == X && b[2] == X && b[1] == empty) {
        return 1;
    }
    if (b[3] == X && b[4] == X && b[5] == empty) {
        return 5;
    } else if (b[4] == X && b[5] == X && b[3] == empty) {
        return 3;
    } else if (b[3] == X && b[5] == X && b[4] == empty) {
        return 4;
    }
    if (b[6] == X && b[7] == X && b[8] == empty) {
        return 8;
    } else if (b[7] == X && b[8] == X && b[6] == empty) {
        return 6;
    } else if (b[6] == X && b[8] == X && b[7] == empty) {
        return 7;
    }
    if (b[0] == X && b[3] == X && b[6] == empty) {
        return 6;
    } else if (b[3] == X && b[6] == X && b[0] == empty) {
        return 0;
    } else if (b[0] == X && b[6] == X && b[3] == empty) {
        return 3;
    }
    if (b[1] == X && b[4] == X && b[7] == empty) {
        return 7;
    } else if (b[4] == X && b[7] == X && b[1] == empty) {
        return 1;
    } else if (b[1] == X && b[7] == X && b[4] == empty) {
        return 4;
    }
    if (b[2] == X && b[5] == X && b[8] == empty) {
        return 8;
    } else if (b[5] == X && b[8] == X && b[2] == empty) {
        return 2;
    } else if (b[2] == X && b[8] == X && b[5] == empty) {
        return 5;
    }
    if (b[0] == X && b[4] == X && b[8] == empty) {
        return 8;
    } else if (b[4] == X && b[8] == X && b[0] == empty) {
        return 0;
    } else if (b[0] == X && b[8] == X && b[4] == empty) {
        return 4;
    }
    if (b[2] == X && b[4] == X && b[6] == empty) {
        return 6;
    } else if (b[4] == X && b[6] == X && b[2] == empty) {
        return 2;
    } else if (b[2] == X && b[6] == X && b[4] == empty) {
        return 4;
    }

    //if cant win or block pick middle side (not corner)
    if (b[1] == empty && b[7] == empty) {
        return 1;
    } else if (b[3] == empty && b[5] == empty) {
        return 3;
    } else if (b[5] == empty && b[3] == empty) {
        return 5;
    } else if (b[7] == empty && b[1] == empty) {
        return 7;
    } else if (b[0] == empty) {
        return 0;
    } else if (b[2] == empty) {
        return 2;
    } else if (b[6] == empty) {
        return 6;
    } else if (b[8] == empty) {
        return 8;
    }

    std::cout << "error";
    return 4;
}

void playerAI() { // runs a player vs. AI game
    static std::array<state, 9> boardState; // the state of the 9 space board
    boardState.fill(empty); // fills the board with empty spaces
    wld game = cont; // win lose draw variable
    bool xTurn = true; // whose turn it is
    int moves = 0; // number of spaces filled
    int space; // players space choice

    std::cout << "The AI will always win or draw." << std::endl;

    while (game == cont && moves < 9) { // while the game has not been won yet or board not filled yet
        if (xTurn == true) { // if x's turn else AI turn
            std::cout << "Your turn!" << std::endl;
            std::cout << "To select your space, please input the number of the tile: ";
            std::cin >> space; // asks for player input for space choice

            bool choosing = true;
            while (choosing) { // while player is choosing a space
                space--;
                if (boardState[space] == empty) { // if the space is empty
                    boardState[space] = X; // assigns the space an X
                    std::cout << std::endl;
                    drawBoard(boardState); // re draws board (visual)
                    choosing = false; // player is no longer choosing
                } else { // if player chooses a filled space
                    std::cout << "That space is not empty!" << std::endl;
                    std::cout << "To select your space, please input the number of the tile: ";
                    std::cin >> space; // asks for input again
                }
            }
            xTurn = false;
        } else { // AI move
            boardState[chooseSpace(boardState)] = O;
            drawBoard(boardState);
            std::cout << "The AI responded." << std::endl;
            xTurn = true;
        }

        game = checkState(boardState); // checks gamestate (win lose draw continue)
        moves++; // number of spaces filled increased
    }

    switch (game) { // when game is over check win lose draw
        case xW : std::cout << "Player Wins!" << std::endl; std::cout << std::endl; break;
        case oW : std::cout << "AI Wins!" << std::endl; std::cout << std::endl; break;
        default : std::cout << "Draw" << std::endl; std::cout << std::endl; break;
    }
}

void pVp() { // runs a player vs. player game
    static std::array<state, 9> boardState; // the state of the 9 space board
    boardState.fill(empty); // fills the board with empty spaces
    wld game = cont; // win lose draw variable
    bool xTurn = true; // whose turn it is
    int moves = 0; // number of spaces filled
    int space; // players space choice
    
    while (game == cont && moves < 9) { // while the game has not been won yet or board not filled yet
        if (xTurn == true) { // if x's turn else o's turn
            std::cout << "X Player's turn!" << std::endl;
            std::cout << "To select your space, please input the number of the tile: ";
            std::cin >> space; // asks for player input for space choice

            bool choosing = true;
            while (choosing) { // while player is choosing a space
                space--;
                if (boardState[space] == empty) { // if the space is empty
                    boardState[space] = X; // assigns the space an X
                    std::cout << std::endl;
                    drawBoard(boardState); // re draws board (visual)
                    choosing = false; // player is no longer choosing
                } else { // if player chooses a filled space
                    std::cout << "That space is not empty!" << std::endl;
                    std::cout << "To select your space, please input the number of the tile: ";
                    std::cin >> space; // asks for input again
                }
            }
            xTurn = false; // no longer x's turn
        } else { // o's turn
            std::cout << "O Player's turn!" << std::endl;
            std::cout << "To select your space, please input the number of the tile: ";
            std::cin >> space; // asks for player input for space choice

            bool choosing = true;
            while (choosing) { // while player is choosing a space
                space--;
                if (boardState[space] == empty) { // if the space is empty
                    boardState[space] = O; // assigns the space an O
                    std::cout << std::endl;
                    drawBoard(boardState); // re draws board (visual)
                    choosing = false; // player is no longer choosing
                } else { // if player chooses a filled space
                    std::cout << "That space is not empty! Or that is an invalid input!" << std::endl;
                    std::cout << "To select your space, please input the number of the tile: ";
                    std::cin >> space; // asks for input again
                }
            }
            xTurn = true; // now is o's turn
        }

        game = checkState(boardState); // checks gamestate (win lose draw continue)
        moves++; // number of spaces filled increased
    }

    switch (game) { // when game is over check win lose draw
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