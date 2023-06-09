#include "functions.h"

#define PLAYGROUND_SIZE 3

// ============================== Global Variables ==============================
// Playground array to store the Xs and Os
char playground[PLAYGROUND_SIZE][PLAYGROUND_SIZE] = {{' ', ' ', ' '},
                                                     {' ', ' ', ' '},
                                                     {' ', ' ', ' '}};

// Lookup table to check if the position is occupied or not
// static because no file except functions.c should access it
static int LookupTable[3][3] = {{11, 12, 13},
                                {21, 22, 23},
                                {31, 32, 33}};

char Turn = 'O';

int position;
// =============================== Functions =====================================
/// @brief Clears the console and prints the playground to the screen
/// @return void (nothing)
void render_playground()
{
    // system("clear"); // for Bash terminal
    system("cls"); // for Windows terminal
    printf("-------------\n");
    for (int i = 0; i < PLAYGROUND_SIZE; i++)
    {
        for (int j = 0; j < PLAYGROUND_SIZE; j++)
        {
            printf("| %c ", playground[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
}

/// @brief Gets the player input and checks if it's valid or not (occupied or out of range)
/// @return int (the position)
/// @note The position is a 2 digit number, the first digit is the row and the second digit is the column
int get_player_input()
{
    int flag = 0; // wrong option by default
    Turn = (Turn == 'X') ? 'O' : 'X';
    do
    {
        printf("%c's turn.. Enter position: ", Turn);
        scanf("%d", &position);

        if ((position / 10) <= 3 && (position / 10) >= 1)
        {
            if (LookupTable[FIRST_DIGIT(position)][SECOND_DIGIT(position)] == 0)
            {
                printf("Position is occupied! try again...\n");
                flag = 0;
            }
            else
            {
                flag = 1;
                LookupTable[FIRST_DIGIT(position)][SECOND_DIGIT(position)] = 0; // position is occupied
            }
        }
        else
        {
            printf("Wrong option! Try again...\n");
            flag = 0;
        }

    } while (flag == 0);

    return position;
}

/// @brief Checks if there is a winner or not (rows, columns, diagonals) and returns the winner
/// @return char (the winner)
/// @note If there is no winner yet, it returns 0
char judge()
{
    int i;
    // no need to check for the diagonals every loop (only 2 diagonals)
    if ((playground[0][0] == playground[1][1]) && (playground[1][1] == playground[2][2])) // right diagonal
    {
        if (playground[0][0] != ' ')
        {
            return playground[0][0];
        }
    }
    if ((playground[0][2] == playground[1][1]) && (playground[1][1] == playground[2][0])) // left diagonal
    {
        if (playground[1][1] != ' ')
        {
            return playground[1][1];
        }
    }

    for (i = 0; i < PLAYGROUND_SIZE; i++)
    {
        if ((playground[i][0] == playground[i][1]) && (playground[i][1] == playground[i][2])) // rows
        {
            if (playground[i][0] != ' ') // if the row is not empty
            {
                return playground[i][0];
            }
        }
        if ((playground[0][i] == playground[1][i]) && (playground[1][i] == playground[2][i])) // columns
        {
            if (playground[0][i] != ' ') // if the column is not empty
            {
                return playground[0][i];
            }
        }
    }

    return 0; // no winner yet
}
