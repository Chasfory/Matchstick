/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** game_players
*/

#include "mastchstick.h"

void game_ia(match_t *game)
{
    int nb_line = 0;
    int nb_sticks = 0;

    nb_line = (random() % (game->nbr_lines) + 1);
    while (game->nbr_stick[nb_line - 1] == 0) {
        nb_line = (random() % (game->nbr_lines) + 1);
    }
    nb_sticks = (random() % (game->nbr_max) + 1);
    while (game->nbr_stick[nb_line - 1] < nb_sticks) {
        nb_sticks = (random() % (game->nbr_max) + 1);
    }
    my_putstr("AI removed ");
    my_put_nbr(nb_sticks);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb_line);
    my_putchar('\n');
    remote_sticks_ia(game, nb_line, nb_sticks);
}

static void display_game_player(char *result_sticks, char *result_line,
                                match_t *game)
{
    my_putstr("Player removed ");
    my_putstr(result_sticks);
    my_putstr(" match(es) from line ");
    my_putstr(result_line);
    remote_sticks(game, result_line, result_sticks);
    my_putchar('\n');
    free(result_line);
    free(result_sticks);
}

static char *game_result_line(char *result_line, match_t *game)
{
    result_line = cut_n(result_line);
    game->error_line =  my_getnbr(result_line);
    my_putstr("Matches: ");
    return result_line;
}

static char *result_line_game(match_t *game)
{
    int tmp = -1;
    size_t buffsize = 0;
    char *result_line = NULL;

    while (tmp == -1) {
        my_putstr("Line: ");
        if (getline(&result_line, &buffsize, stdin) == -1) {
            return NULL;
        }
        tmp = check_error_lines(result_line, game);
        if (tmp == -1) {
            free(result_line);
            result_line = NULL;
            buffsize = 0;
        }
    }
    return result_line;
}

int game_player(match_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    init_struct_player(player);
    my_putstr("\nYour turn:\n");
    while (player->tmp == -1) {
        player->result_line = result_line_game(game);
        if (player->result_line == NULL)
            return -1;
        player->result_line = game_result_line(player->result_line, game);
        player->buffsize = 0;
        if (getline(&player->result_sticks, &player->buffsize, stdin) == -1)
            return -1;
        player->tmp = check_error_sticks(player->result_sticks, game,
                        game->error_line);
        error_game(player);
    }
    player->result_sticks = cut_n(player->result_sticks);
    display_game_player(player->result_sticks, player->result_line, game);
    return 0;
}