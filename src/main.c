/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-2-matchstick-laetitia.bousch
** File description:
** main
*/

#include "mastchstick.h"

int main(int ac, char **av)
{
    int result = 0;

    if (error_handling(ac, av) == -1) {
        return 84;
    }
    srandom(time(NULL));
    result = gameplay(av);
    if (result == -1) {
        return 0;
    }
    return result;
}