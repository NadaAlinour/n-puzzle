// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <chrono>

#include "board.hpp"

using namespace std;

void searchBFS(Board board);
void getPath(Board board);

int main()
{
    int n = 3;
    vector<vector<int>> initialState = {{1, 0, 2}, {3, 4, 5}, {6, 7, 8}};

    Board board(n, initialState);
    board.printState();
    cout << "......................\n";


    auto start = std::chrono::high_resolution_clock::now();
    searchBFS(board);
    auto end = std::chrono::high_resolution_clock::now();

    // get number of microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "(BFS) running time in microseconds: " << duration.count() << " µs\n";


    return 0;
}