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

void performAction(const PuzzleState *currentState, const int *action[][], PuzzleState *resultState)
{
    int possibleMovements[4][2] = possibleActions(currentState);
    int i_0, j_0;
    for (int i = 0; i < 4; i++)
    {
        int new_i = i_0 + possibleMovements[i][0];
        int new_j = j_0 + possibleMovements[i][1];
        if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3)
        {
            resultState->board[new_i][new_j] = currentState->board[i_0][j_0];
            resultState->board[i_0][j_0] = currentState->board[new_i][new_j];
        }
    }
}

int **possibleActions(const PuzzleState *state)
{
    // know where 0 is
    int i_0, j_0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state->board[i][j] == 0)
            {
                i_0 = i;
                j_0 = j;
            }
        }
    }

    // Define possible movements: up, down, left, right
    int movements[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int possibleMovements[4][2];
    int count = 0;

    // Check each possible movement
    for (int i = 0; i < 4; i++)
    {
        int new_i = i_0 + movements[i][0];
        int new_j = j_0 + movements[i][1];

        // If the new position is within the bounds of the board, add it to possibleMovements
        if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3)
        {
            possibleMovements[count][0] = movements[i][0];
            possibleMovements[count][1] = movements[i][1];
            count++;
        }
    }
    return possibleMovements;
}
void possibleActions(const PuzzleState *state)
{
    // know where 0 is
    int i_0, j_0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            if (state->board[i][j] == 0)
                i_0, j_0 = i, j;
        }
    }
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