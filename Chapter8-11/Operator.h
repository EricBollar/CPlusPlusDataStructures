#include <iostream>

enum game {c4};

class Operator {
    private:
        void CFour(); // Connect Four
    public:
        void run(game g); // Runs given game
};