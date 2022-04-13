/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** remote_stick
*/

#include "mastchstick.h"

void remote_sticks(match_t *game, char *result_line, char *result_sticks)
{
    int r_line = my_getnbr(result_line);
    int r_sticks = my_getnbr(result_sticks);
    int tmp = 0;

    game->nbr_stick[r_line - 1] = game->nbr_stick[r_line - 1] - r_sticks;
    for (int i = 0; game->game[r_line][i] != '\0'; i++) {
        if (game->game[r_line][i] == '|' && tmp <
        game->nbr_stick[r_line - 1]) {
            tmp++;
        } else if (game->game[r_line][i] == '|' && tmp >=
        game->nbr_stick[r_line - 1]) {
            game->game[r_line][i] = ' ';
        }
    }
}

void remote_sticks_ia(match_t *game, int r_line, int r_sticks)
{
    int tmp = 0;

    game->nbr_stick[r_line - 1] = game->nbr_stick[r_line - 1] - r_sticks;
    for (int i = 0; game->game[r_line][i] != '\0'; i++) {
        if (game->game[r_line][i] == '|' && tmp <
        game->nbr_stick[r_line - 1]) {
            tmp++;
        } else if (game->game[r_line][i] == '|' && tmp >=
        game->nbr_stick[r_line - 1]) {
            game->game[r_line][i] = ' ';
        }
    }
}