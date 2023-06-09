// header guard
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define FIRST_DIGIT(num) (((num) / 10) - 1)
#define SECOND_DIGIT(num) (((num) % 10) - 1)

int get_player_input();
void make_computer_move();
char judge();

#endif // FUNCTIONS_H