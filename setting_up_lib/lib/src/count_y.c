/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup-noah.gomes
** File description:
** count_y for setting up project
*/

#include "../../../lib/include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int count_y(char *buffer)
{
    int i = 0;
    int counter = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            counter++;
        i++;
    }
    return counter - 1;
}
