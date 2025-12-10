#include <iostream>
#include <vector>

class Board
{

public:
    int n; // size of n-puzzle
    std::vector<std::vector<int>> tiles;
    int x; // x and y to track the position of the zero tile (i think)
    int y;
    Board *parent; // pointer to the current state's parent in order to get the path later(?)

public:
    // (!): have to resize the vector first so it has allocated space to initialize

    Board(int n, std::vector<std::vector<int>> &state, Board *parent = nullptr) : n(n), tiles(state), parent(parent)
    {
        //std::cout << "Initializing board.." << "\n";
        // find empty tile position
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tiles[i][j] == 0)
                {
                    this->x = i;
                    this->y = j;
                }
            }
        }
    }

    /* method to print the state of the board (node) */
    void printState()
    {
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

    /* overloading the == operator for unordered_set*/
    bool operator==(const Board* other) const
    {
        if (this->tiles == other->tiles)
            return true;
        else
            return false;
    }

    /* hash function for unordered_set*/
    struct HashFunction
    {
        size_t operator()(const Board* board) const
        {
            size_t h = 0;
            for (int i = 0; i < board->n; i++)
            {
                for (int j = 0; j < board->n; j++)
                {
                    h = h * 31 + std::hash<int>()(board->tiles[i][j]);
                }
            }
            return h;
        }
    };

    /* method to test if current tiles match goal - returns 1 if equal, 0 otherwise */
    int isGoal()
    {
        return this->tiles == std::vector<std::vector<int>>{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    }

    /* checks if move is valid, returns 1 if true and 0 otherwise */
    int isValidMove(char move)
    {
        /*so apparently if a case does not return it continues on to the following cases so we should break,
       the point of the case is that it starts at the matching one -
       if we dont break out of the case it falls through to the case after :\ */
        switch (move)
        {
        case 'r':
            if (this->y + 1 < this->n)
                return 1;
            break;
        case 'l':
            if (this->y - 1 >= 0)
                return 1;
            break;
        case 'u':
            if (this->x - 1 >= 0)
                return 1;
            break;
        case 'd':
            if (this->x + 1 < this->n)
                return 1;
            break;
        default:
            std::cout << "Invalid move option..\n";
            break;
        }

        return 0;
    }

    /* generalized move method, destination coordinates provided as params */
    Board* move(Board *parent, int xCoordinate, int yCoordinate)
    {
        Board *newBoard = new Board(this->n, this->tiles, parent); // probably redundant

        std::swap(newBoard->tiles[newBoard->x][newBoard->y], newBoard->tiles[xCoordinate][yCoordinate]);
        newBoard->x = xCoordinate;
        newBoard->y = yCoordinate;

        return newBoard;
    }

    /* TODO: method to get parents up to root */
    
    
};
