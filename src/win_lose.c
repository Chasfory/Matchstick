/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** win_lose
*/

#include "mastchstick.h"

int check_win_or_lose(match_t *game)
{
    for (int i = 0; i < game->nbr_lines; i++) {
        if (game->nbr_stick[i] != 0) {
            return 0;
        }
    }
    return 1;
}