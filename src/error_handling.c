/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** error_handling
*/

#include "mastchstick.h"

int error_handling(int ac, char **av)
{
    if (ac != 3) {
        return -1;
    }
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] < '0' || av[i][j] > '9') {
                return -1;
            }
        }
    }
    return 0;
}

void error_game(player_t *player)
{
    if (player->tmp == -1) {
        free(player->result_sticks);
        player->result_sticks = NULL;
        player->buffsize = 0;
    }
}