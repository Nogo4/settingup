/*
** EPITECH PROJECT, 2024
** G1 - Unix System Programming
** File description:
** my_ls project
*/

#include <stdio.h>

int my_argc(char **av)
{
    int i = 0;

    while (av[i] != NULL)
        i++;
    return i;
}
