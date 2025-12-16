#include "board.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

/* method to get neighbours by applying all possible board moves */
vector<Board *> getNeighbours(Board *board)
{
    vector<Board *> neighbours;

    if (board->isValidMove('u'))
        neighbours.push_back(board->move(board, board->x - 1, board->y));

    if (board->isValidMove('d'))
        neighbours.push_back(board->move(board, board->x + 1, board->y));

    if (board->isValidMove('l'))
        neighbours.push_back(board->move(board, board->x, board->y - 1));

    if (board->isValidMove('r'))
        neighbours.push_back(board->move(board, board->x, board->y + 1));

    return neighbours;
}

Board *searchBFS(Board *board)
{
    int nodes_expanded = 0;
    unordered_set<Board *, Board::HashFunction, Board::BoardEqual> explored;

    queue<Board *> frontier;
    unordered_set<Board *, Board::HashFunction> inFrontier; // frontier lookup

    frontier.push(board); // push initial state to the queue
    inFrontier.insert(board);

    int frontier_size = 0;
    int k = 0;
    while (!frontier.empty())
    {
        frontier_size = frontier.size();

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

            // get neighbours
            vector<Board *> neighbours = getNeighbours(currBoard);

            // explore neighbours
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
    return board;
}

Board *searchDFS(Board *board)
{
    int nodes_expanded = 0;
    unordered_set<Board *, Board::HashFunction, Board::BoardEqual> explored;

    stack<Board *> frontier;
    unordered_set<Board *, Board::HashFunction> inFrontier; // frontier lookup

    frontier.push(board); // push initial state to the queue
    inFrontier.insert(board);

    while (!frontier.empty())
    {
        Board *currBoard = frontier.top();

        frontier.pop();
        nodes_expanded += 1;

        explored.insert(currBoard);

        if (currBoard->isGoal())
        {
            cout << "Found goal state.. \n";
            cout << "nodes expanded: " << nodes_expanded - 1 << "\n";

            return currBoard;
        }

        // get neighbours
        vector<Board *> neighbours = getNeighbours(currBoard);

        // explore neighbours
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

    cout << "didnt find a solution..\n";
    return board; // return current board (last i guess?)
}
