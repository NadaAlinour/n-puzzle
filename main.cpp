// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <optional>

#include "board.hpp"

using namespace std;

void searchBFS(Board board)
{
    unordered_set<Board, Board::HashFunction> explored;
    queue<Board> frontier;
    frontier.push(board); // push initial state to the queue
    unordered_set<Board, Board::HashFunction> inFrontier;
    inFrontier.insert(board);

    // gonna print out the boards generated level by level
    // cuz something is def wrong
    // and also i want to say that i can encode the tiles into a string to insert into the sets
    // since apparently strings have their own hashing(?) so i wouldnt have ot write a hashing
    // function(?) :)
    int frontier_size = 0;
    int k = 0;
    while (!frontier.empty())
    {
        cout << "LEVEL " << k++ << "\n";
        frontier_size = frontier.size();
        cout << "size: " << frontier_size << "\n";

        for (int i = 0; i < frontier_size; i++)
        {
            Board currBoard = frontier.front();
            frontier.pop();
            explored.insert(currBoard);
            cout << "CURRENT POPPED: \n";
            currBoard.printState();

            if (currBoard.isGoal())
            {
                cout << "Found goal state.. \n";
                return;
            }

            // get child states
            vector<Board> neighbours;

            if (currBoard.isValidMove('u'))
            {
                // cout << "moving upwards\n";
                neighbours.push_back(currBoard.move(currBoard.x - 1, currBoard.y));
            }
            if (currBoard.isValidMove('d'))
            {
                // cout << "moving downwards\n";
                neighbours.push_back(currBoard.move(currBoard.x + 1, currBoard.y));
            }
            if (currBoard.isValidMove('r'))
            {
                // cout << "moving righwards\n";
                neighbours.push_back(currBoard.move(currBoard.x, currBoard.y + 1));
            }
            if (currBoard.isValidMove('l'))
            {
                // cout << "moving leftwards\n";
                neighbours.push_back(currBoard.move(currBoard.x, currBoard.y - 1));
            }

            // explore neighbours
            for (Board neighbour : neighbours)
            {
                cout << "\n";

                if (!explored.count(neighbour) && !inFrontier.count(neighbour))
                {
                    cout << "im pushed" << "\n";
                    neighbour.printState();

                    frontier.push(neighbour);
                    inFrontier.insert(neighbour);
                }
            }
        }
    }

    cout << "didnt find a solution..\n";
}

int main()
{
    int n = 3;
    vector<vector<int>> initialState = {{1, 2, 5}, {3, 4, 0}, {6, 7, 8}};

    Board board(n, initialState);
    board.printState();

    searchBFS(board);

    return 0;
}