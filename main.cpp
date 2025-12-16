// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

#include "board.hpp"

using namespace std;

// make sure to update the function prototype if the definition changes(?)
Board *searchBFS(Board *board);
Board *searchDFS(Board *board);

int main()
{
    string choice_s;
    int choice;

    while (true)
    {
        cout << "Please choose a search algorithm: \n";
        cout << "1. BFS (Breadth first search)\n";
        cout << "2. DFS (Depth first search)\n";

        cout << "\n-> ";

        cin >> choice_s;

        // handling invalid input
        if (choice_s == "1" || choice_s == "2")
        {
            choice = stoi(choice_s);
            break;
        }

        cout << "Invalid input. Please try again.\n\n";
        continue;
    }

    /* INITIALIZATION */
    int n = 3;
    // vector<vector<int>> initialState = {{1, 0, 2}, {3, 4, 5}, {6, 7, 8}};
    vector<vector<int>> initialState = {{1, 2, 5}, {3, 4, 0}, {6, 7, 8}};

    Board *board = new Board(n, initialState);
    cout << "Initial state: \n";
    board->printState();

    /* SEARCH AND RESULTS */
    auto start = std::chrono::high_resolution_clock::now();

    if (choice == 1)
        Board *goal = searchBFS(board);
    else if (choice == 2)
        Board *goal = searchDFS(board);

    auto end = std::chrono::high_resolution_clock::now();

    // get number of microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Running time in microseconds: " << duration.count() << " µs\n";

    // print path to parent
    // goal->getPathToParent();

    return 0;
}