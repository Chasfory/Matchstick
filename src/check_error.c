/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** check_error
*/

#include "mastchstick.h"

int check_error_lines(char *result_line, match_t *game)
{
    int attack_line = 0;

    for (int i = 0; result_line[i] != '\n'; i++) {
        if (result_line[i] < '0' || result_line[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return -1;
        }
    }
    attack_line = my_getnbr(result_line);
    if (attack_line > game->nbr_lines || attack_line == 0) {
        my_putstr("Error: this line is out of range\n");
        return -1;
    }
    return 0;
}

static int check_error_sticks_bis(char *result_sticks, match_t * game,
                            int error_line, int attack_line)
{
    if (attack_line == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return -1;
    }
    if (attack_line > game->nbr_max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->nbr_max);
        my_putstr(" matches per turn\n");
        return -1;
    }
    if (game->nbr_stick[error_line - 1] < attack_line) {
        my_putstr("Error: not enough matches on this line\n");
        return -1;
    }
    return 0;
}

int check_error_sticks(char *result_sticks, match_t * game, int error_line)
{
    int attack_line = 0;

    for (int i = 0; result_sticks[i] != '\n'; i++) {
        if (result_sticks[i] < '0' || result_sticks[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return -1;
        }
    }
    attack_line = my_getnbr(result_sticks);
    if (check_error_sticks_bis(result_sticks,
        game, error_line, attack_line) == -1) {
        return -1;
    }
    return 0;
}