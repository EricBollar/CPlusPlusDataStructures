#include <iostream>
#include <string>
#include <array>

enum tile {blue, red, white};

class ConnectFour {
    std::array<std::array<tile, 7>, 6> board; // board[row][column]

    public:
        std::string tileDraw(tile t); // returns 🔵🔴⚪ string value for each given enum tile
        tile checkWin(); // checks every win state
        void drawBoard(); // draws current board state
        void resetBoard(); // fills board with white tile vals (⚪)
        bool selectColumn(int c, tile turn); // places a tile in a players choice of column
};