/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** play_game
*/

#include "mastchstick.h"

static void display_maps(match_t *game)
{
    for (int i = 0; i <= (game->nbr_lines + 1); i++) {
        my_putstr(game->game[i]);
        my_putchar('\n');
    }
}

static int script_game(match_t *game)
{
    if (game_player(game) == -1) {
        return -1;
    }
    display_maps(game);
    if (check_win_or_lose(game) == 1) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    my_putstr("\nAI's turn...\n");
    game_ia(game);
    display_maps(game);
    if (check_win_or_lose(game) == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    return 0;
}

int play_game(match_t *game)
{
    int result = 0;

    display_maps(game);
    while (result == 0) {
        result = script_game(game);
    }
    return result;
}