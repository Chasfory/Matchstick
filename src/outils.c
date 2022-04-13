/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** outils
*/

#include "mastchstick.h"

char *cut_n(char *av)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(av) + 1));
    int i = 0;

    if (tmp == NULL) {
        return NULL;
    }
    for (i = 0; av[i] != '\n' && av[i] != '\0'; i++) {
        tmp[i] = av[i];
    }
    tmp[i] = '\0';
    return tmp;
}

void init_struct_player(player_t *player)
{
    player->buffsize = 0;
    player->result_line = NULL;
    player->result_sticks = NULL;
    player->tmp = -1;
}