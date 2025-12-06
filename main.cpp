#include <bits/stdc++.h>
using namespace std;

class Board
{
    int n; // size of n-puzzle
    vector<vector<int>> board;

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
        this->board.resize(n, vector<int>(n));

        cout << "Initializing board.." << "\n";

        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                this->board[i][j] = state[k++];

                cout << this->board[i][j] << " ";
            }

            cout << "\n";
        }
            
    }
        
};

int main()
{
    cout << "Enter n-puzzle size: " << "\n";
    int n;
    cin >> n;

    cout << "Enter initial board state: " << "\n";
    vector<int> initialState(n*n);

    for(int i = 0; i < n*n; i++) {
        cin >> initialState[i];
    }

    //int n = 3;
    //vector<int> initialState = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    Board newBoard(n, initialState);

    return 0;
}