// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

#include "board.hpp"

using namespace std;



int main()
{
    /*cout << "Enter n-puzzle size: " << "\n";
    int n;
    cin >> n;

    cout << "Enter initial board state: " << "\n";
    vector<int> initialState(n*n);

    // update to fill in a 2d vector
    for(int i = 0; i < n*n; i++) {
        cin >> initialState[i];
    }*/

    int n = 3;
    vector<vector<int>> initialState = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    Board newBoard(n, initialState);
    newBoard.printState();

    return 0;
}