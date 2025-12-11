#include "board.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

Board *searchBFS(Board *board)
{
    int nodes_expanded = 0;
    unordered_set<Board *, Board::HashFunction, Board::BoardEqual> explored;
     
    queue<Board *> frontier;
    unordered_set<Board *, Board::HashFunction> inFrontier; // frontier lookup

    frontier.push(board); // push initial state to the queue
    inFrontier.insert(board);

    vector<Board *> neighbours;

    int frontier_size = 0;
    int k = 0;
    while (!frontier.empty())
    {
        cout << "LEVEL " << k++ << "\n";
        frontier_size = frontier.size();
        cout << "size: " << frontier_size << "\n";

        for (int i = 0; i < frontier_size; i++)
        {
            Board *currBoard = frontier.front();
            frontier.pop();
            nodes_expanded += 1;

            explored.insert(currBoard);

            if (currBoard->isGoal())
            {
                cout << "Found goal state.. \n";
                cout << "nodes expanded: " << nodes_expanded - 1 << "\n";
                
                return currBoard;
            }

            // get child states

            if (currBoard->isValidMove('u'))
                neighbours.push_back(currBoard->move(currBoard, currBoard->x - 1, currBoard->y));

            if (currBoard->isValidMove('d'))
                neighbours.push_back(currBoard->move(currBoard, currBoard->x + 1, currBoard->y));

            if (currBoard->isValidMove('r'))
                neighbours.push_back(currBoard->move(currBoard, currBoard->x, currBoard->y + 1));

            if (currBoard->isValidMove('l'))
                neighbours.push_back(currBoard->move(currBoard, currBoard->x, currBoard->y - 1));

            // explore neighbours
            cout << "......................\n";

            for (Board *neighbour : neighbours)
            {
                if (!explored.count(neighbour) && !inFrontier.count(neighbour))
                {                    
                    frontier.push(neighbour);
                    inFrontier.insert(neighbour);
                } 
            }

            neighbours.clear();
            
        }
    }

    cout << "didnt find a solution..\n";
    return board; // return root
}
