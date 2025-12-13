// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <chrono>

#include "board.hpp"

using namespace std;


// make sure to update the function prototype if the definition changes(?)
Board* searchBFS(Board* board);
Board* searchDFS(Board* board);


int main()
{
    int n = 3;
    //vector<vector<int>> initialState = {{1, 0, 2}, {3, 4, 5}, {6, 7, 8}};
    vector<vector<int>> initialState = {{1, 2, 5}, {3, 4, 0}, {6, 7, 8}};


    Board* board = new Board(n, initialState);
    board->printState();
    cout << "......................\n";

    /* ................... BREADTH FIRST SEARCH ....................*/

    auto start = std::chrono::high_resolution_clock::now();
    //Board* goal = searchBFS(board);
    Board* goal = searchDFS(board);

    auto end = std::chrono::high_resolution_clock::now();

    // get number of microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "(BFS) running time in microseconds: " << duration.count() << " µs\n";

    // print path to parent
    //goal->getPathToParent();
    


    return 0;
}