#include <iostream>
#include <vector>


class Board
{

    int n; // size of n-puzzle
    std::vector<std::vector<int>> tiles;
    int x; // x and y to track the position of the zero tile (i think)
    int y;
    Board* parent; // pointer to the current state's parent in order to get the path later(?)

public:
    
    // (!): have to resize the vector first so it has allocated space to initialize

    Board(int n, std::vector<std::vector<int>> &state):n(n), tiles(state)
    {
        std::cout << "Initializing board.." << "\n";
    }

    /* method to print the state of the board (node) */
    void printState() {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << this->tiles[i][j] << " ";
            }

            std::cout << "\n";

        }
            std::cout << "\n";
    }

    /* method to test if current tiles match goal 
     * returns 1 if equal, 0 otherwise 
    */
    int isGoal() {
        std::vector<std::vector<int>> goalState = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

        return this->tiles == goalState;
    }

    /* checks if move is valid, returns 1 if true and 0 otherwise */
    int isValidMove(char move) {
        switch(move) {
            case 'r':
                if (this->y + 1 < this->n) return 1;
            case 'l':
                if (this->y - 1 >= 0) return 1;
            case 'u':
                if (this->x - 1 >= 0) return 1;
            case 'd':
                if (this->x + 1 < this->n) return 1;
            default:
                std::cout << "Invalid move option..\n";
                break;
        }

        return -1;
    }

    Board moveRight() {
            Board newBoard(*this); // *this copies the constructor since i want an exact copy of the object

            std::swap(newBoard.tiles[newBoard.x][newBoard.y], newBoard.tiles[newBoard.x][newBoard.y + 1]);
            newBoard.y++; 

            std::cout << "moving to the right..\n";
            newBoard.printState();
            return newBoard;
    }

    Board moveLeft() {
            Board newBoard(*this); 
            
            std::swap(newBoard.tiles[newBoard.x][newBoard.y], newBoard.tiles[newBoard.x][newBoard.y - 1]);
            newBoard.y--; 

            std::cout << "moving to the left..\n";
            newBoard.printState();
            return newBoard;
    }

    Board moveUp() {
            Board newBoard(*this); 

            std::swap(newBoard.tiles[newBoard.x][newBoard.y], newBoard.tiles[newBoard.x - 1][newBoard.y]);
            newBoard.x--; 

            std::cout << "moving upward..\n";
            newBoard.printState();
            return newBoard;
    }

    Board moveDown() {
            Board newBoard(*this); 

            std::swap(newBoard.tiles[newBoard.x][newBoard.y], newBoard.tiles[newBoard.x + 1][newBoard.y]);
            newBoard.x++; 

            std::cout << "moving downwards..\n";
            newBoard.printState();
            return newBoard;
    }

};
