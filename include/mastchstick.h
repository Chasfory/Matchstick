/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** mastchstick
*/

#ifndef MASTCHSTICK_H_
#define MASTCHSTICK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#include "my.h"

typedef struct match_s {
    char **game;
    int *nbr_stick;
    int nbr_lines;
    int nbr_last_line;
    int nbr_max;
    int stick;
    int error_line;
    int error_sticks;
} match_t;

typedef struct player_s {
    char *result_sticks;
    char *result_line;
    int tmp;
    size_t buffsize;
} player_t;

// check_error
int check_error_sticks(char *result_sticks, match_t * game, int error_line);
int check_error_lines(char *result_line, match_t *game);

// error_handling
int error_handling(int ac, char **av);
void error_game(player_t *player);

// game_players
int game_player(match_t *game);
void game_ia(match_t *game);

// gameplay
int gameplay(char **av);

// outils
char *cut_n(char *av);
void init_struct_player(player_t *player);

// play_game
int play_game(match_t *game);

// remote_stick
void remote_sticks_ia(match_t *game, int r_line, int r_sticks);
void remote_sticks(match_t *game, char *result_line, char *result_sticks);

// win_lose
int check_win_or_lose(match_t *game);

#endif /* !MASTCHSTICK_H_ */