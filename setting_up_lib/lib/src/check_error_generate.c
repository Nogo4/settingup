/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup-noah.gomes
** File description:
** functions to find if format of generating map is good
*/

#include "../../../lib/include/my.h"
#include "../include/lib_setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int check_verif_format_patern(char *av)
{
    int i = 0;

    while (av[i] != '\0') {
        if (av[i] != '.' && av[i] != 'o'
            && av[i] != '"')
            return 1;
        i++;
    }
    return 0;
}

int check_error_generator(char **av, int len)
{
    if (len <= 0)
        return 1;
    if (check_verif_format_patern(av[2]) == 1)
        return 1;
    if (my_strlen(av[2]) == 0)
        return 1;
    return 0;
}
