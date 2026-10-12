#include <iostream>
#include <string>

class Player {
    private:
        char symbol;
        std::string name;

    public:
        Player(char sym = 'X', std::string n = "Player X") : symbol(sym), name(n) {}

        char getSymbol() const { return symbol; }
        std::string getName() const { return name; }
};

class Board {
    private: 
        char grid[3][3];
        int filledcells;
    
    public:
        Board() : filledcells(0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    grid[i][j] = ' ';
                }
            }
        }

        void drawBoard() const {
            std::cout << " --------------" << std::endl;

            for (int i = 0; i < 3; i++) {
                std::cout << " | ";
                for (int j = 0; j < 3; j++) {
                    std::cout << grid[i][j] << " | ";
                }
                std::cout << std::endl << " --------------" << std::endl;
            }
        }

        bool isValidMove(int row, int col) const {
            return (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ');
        }

        void makeMove(int row, int col, char symbol) {
            if (isValidMove(row, col)) {
                grid[row][col] = symbol;
                filledcells++;
            }
        }

        bool checkWin(char symbol) const {
            for (int i = 0; i < 3; i++) {
                if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
                    return true;
                }
            }
            
            for (int i = 0; i < 3; i++) {
                if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) {
                    return true;
                }
            }

            if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
                return true;
            }

            if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
                return true;
            }

            return false;
        }

        bool isFull() const {
            return filledcells == 9;
        }

        int countFilledCells() const {
            return filledcells;
        }
};

class TicTacToe {
    private: 
        Board board;
        Player players[2];
        int currentPlayerIndex;

    public: 
        TicTacToe() : currentPlayerIndex(0) {
            players[0] = Player('X', "Player X");
            players[1] = Player('O', "Player O");
        }

        Player& getCurrentPlayer() {
            return players[currentPlayerIndex];
        }

        void switchTurn() {
            currentPlayerIndex = (currentPlayerIndex + 1) %  2;
        }

        void play() {
            int row, col;
            std::cout << "Start Playing Tic Tac Toes!" << std::endl;

            while(!board.isFull()) {
                board.drawBoard();

                Player& currentPlayer = getCurrentPlayer();

                while(true) {
                    std::cout << currentPlayer.getName() << " enter row(1-3) and column(1-3): ";
                    std::cin >> row >> col;
                    row--; col--;

                    if(board.isValidMove(row, col)) {
                        break;
                    }
                    else {
                        std::cout << "Invalid move. Try again dumb!" << std::endl;
                    }

                }

                board.makeMove(row, col, currentPlayer.getSymbol());

                if(board.checkWin(currentPlayer.getSymbol())) {
                    board.drawBoard();
                    std::cout << currentPlayer.getName() << " winssss YAYYAYA!!!" << std::endl;
                    return;
                }

                switchTurn();
            }

            board.drawBoard();
            std::cout << "It's a draw!" << std::endl;
        }
};


int main () {
    TicTacToe game;

    game.play();
    return 0;
}