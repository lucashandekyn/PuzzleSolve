#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

typedef struct
{
    int board[BOARD_SIZE][BOARD_SIZE];
} PuzzleState;

void printState(const PuzzleState *state)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            printf("%d ", state->board[i][j]);
        }
        printf("\n");
    }
}

bool areStatesEqual(const PuzzleState *state1, const PuzzleState *state2)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (state1->board[i][j] != state2->board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool isGoalState(const PuzzleState *state)
{
    PuzzleState goalState = {
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 0}}}; // 0 represents the empty space

    return areStatesEqual(state, &goalState);
}

void performAction(const PuzzleState *currentState, int action, PuzzleState *resultState)
{
}

void breadthFirstSearch(const PuzzleState *initialState)
{
}

int main()
{
    // Example initial state
    PuzzleState initialState = {
        {{1, 2, 3},
         {4, 0, 5},
         {7, 8, 6}}}; // 0 represents the empty space

    breadthFirstSearch(&initialState);

    return 0;
}