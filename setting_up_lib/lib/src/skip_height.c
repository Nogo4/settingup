/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup-noah.gomes
** File description:
** count_x for setting up project
*/

#include "../../../lib/include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int skip_height(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    return i + 1;
}
