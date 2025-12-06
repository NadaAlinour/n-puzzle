// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Board
{
    int n; // size of n-puzzle
    vector<vector<int>> tiles;
    Board* parent; // pointer to the current state's parent in order to get the path later(?)

public:
    // get size of board and the initial state (as an array) to populate the matrix
    // 012345678
    // 0 1 2
    // 3 4 5
    // 6 7 8
    // (!): have to resize the vector first so it has allocated space to initialize

    Board(int n, vector<int> state)
    {
        this->n = n;
        this->tiles.resize(n, vector<int>(n));

        cout << "Initializing board.." << "\n";

        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                this->tiles[i][j] = state[k++];

                cout << this->tiles[i][j] << " ";
            }

            cout << "\n";
        }
            
    }

    // method to print the state of the board (node)
    void printState() {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << this->tiles[i][j] << " ";
            }

            cout << "\n";
        }
    }

    // method to test if current tiles match goal tiles
    // returns 1 if equal, 0 otherwise
    int isGoal() {
        vector<vector<int>> goalState = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

        return this->tiles == goalState;
    }

    
};



int main()
{
    /*cout << "Enter n-puzzle size: " << "\n";
    int n;
    cin >> n;

    cout << "Enter initial board state: " << "\n";
    vector<int> initialState(n*n);

    for(int i = 0; i < n*n; i++) {
        cin >> initialState[i];
    }*/

    int n = 3;
    vector<int> initialState = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    Board newBoard(n, initialState);
    int isEqual = newBoard.isGoal();


    return 0;
}