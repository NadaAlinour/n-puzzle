#include "board.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void searchBFS(Board board)
{   int nodes_expanded = 0;
    unordered_set<Board, Board::HashFunction> explored;
    queue<Board> frontier;
    frontier.push(board); // push initial state to the queue
    unordered_set<Board, Board::HashFunction> inFrontier;
    inFrontier.insert(board);

    
    int frontier_size = 0;
    int k = 0;
    while (!frontier.empty())
    {
        cout << "LEVEL " << k++ << "\n";
        frontier_size = frontier.size();
        cout << "size: " << frontier_size << "\n";
        nodes_expanded += frontier_size;

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
                cout << "nodes expanded: " << nodes_expanded << "\n";

                return;
            }

            // get child states
            vector<Board> neighbours;

            if (currBoard.isValidMove('u'))
                neighbours.push_back(currBoard.move(currBoard.x - 1, currBoard.y));

            if (currBoard.isValidMove('d'))
                neighbours.push_back(currBoard.move(currBoard.x + 1, currBoard.y));

            if (currBoard.isValidMove('r'))
                neighbours.push_back(currBoard.move(currBoard.x, currBoard.y + 1));

            if (currBoard.isValidMove('l'))
                neighbours.push_back(currBoard.move(currBoard.x, currBoard.y - 1));

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