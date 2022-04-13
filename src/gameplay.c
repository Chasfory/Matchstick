/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** gameplay
*/

#include "mastchstick.h"

static void init_struct(char **av, match_t *game)
{
    int compt_line = 1;
    int tmp = 1;

    game->stick = 1;
    game->error_line = 0;
    game->error_sticks = 0;
    game->nbr_lines = my_getnbr(av[1]);
    game->nbr_stick = malloc(sizeof(int) * (game->nbr_lines + 1));
    game->nbr_stick[0] = 1;
    for (int j = 1; j < game->nbr_lines; j++) {
        tmp += 2;
        game->nbr_stick[j] = tmp;
    }
    game->nbr_max = my_getnbr(av[2]);
    for (int i = 1; i < game->nbr_lines; i++) {
        compt_line += 2;
    }
    game->nbr_last_line = compt_line;
    game->game = malloc(sizeof(char *) * (game->nbr_lines + 3));
}

static int init_maps_bis(match_t *game, int i, int j)
{
    int compt_match = 0;

    if (i == 0 || i == game->nbr_lines + 1 || j == 0) {
        game->game[i][j] = '*';
    } else {
        compt_match = (game->nbr_last_line - game->stick) / 2;
        for (int str = 0; str < compt_match; str++, j++) {
            game->game[i][j] = ' ';
        }
        for (int compt = 0; compt < game->stick; compt++, j++) {
            game->game[i][j] = '|';
        }
        for (int str = 0; str < compt_match; str++, j++) {
            game->game[i][j] = ' ';
        }
        game->game[i][j] = '*';
        game->stick += 2;
    }
    return j;
}

static int init_maps(match_t *game)
{
    int i = 0;
    int j = 0;

    for (i = 0; i <= (game->nbr_lines + 1); i++) {
        game->game[i] = malloc(sizeof(char) * (game->nbr_last_line + 3));
        if (game->game[i] == NULL) {
            return -1;
        }
        for (j = 0; j <= (game->nbr_last_line + 1); j++) {
            j = init_maps_bis(game, i, j);
        }
        game->game[i][j] = '\0';
    }
    game->game[i] = NULL;
    return 0;
}

void funct_free(match_t *game)
{
    for (int i = 0; i < game->nbr_lines + 3; i++) {
        free(game->game[i]);
    }
    free(game->game);
    free(game->nbr_stick);
}

int gameplay(char **av)
{
    int result = 0;
    match_t game;

    init_struct(av, &game);
    if ((game.nbr_lines <= 1 || game.nbr_lines > 100) || game.nbr_max <= 1) {
        return 84;
    }
    if (game.game == NULL) {
        return -1;
    }
    if (init_maps(&game) == -1) {
        return -1;
    }
    result = play_game(&game);
    funct_free(&game);
    return result;
}