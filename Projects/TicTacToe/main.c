#include "functions.h"

extern char playground[3][3];
extern char Turn;
extern int position;

int main()
{
    int empty_positions = 9;
    do
    {
        render_playground();

        // check for a winner should be done before getting the player input and after rendering the playground
        char winner = judge();
        if (winner != 0)
        {
            printf("The winner is %c\n", winner);
            exit(0);
        }

        position = get_player_input();
        playground[FIRST_DIGIT(position)][SECOND_DIGIT(position)] = Turn;

        empty_positions--;
    } while (empty_positions > 0);

    printf("It's a draw!\n"); // if the loop ends and no winner is found (we don't exit the program)
}
