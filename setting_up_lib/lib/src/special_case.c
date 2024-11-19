/*
** EPITECH PROJECT, 2024
** G1 - Unix System Programming
** File description:
** setting up project
*/

#include "../../../lib/include/my.h"
#include "../include/lib_setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char **case_height_equal_one(char **map)
{
    int i = 0;

    while (map[0][i] != '\0') {
        if (map[0][i] == '.') {
            map[0][i] = 'x';
            return map;
        }
    }
    return map;
}

int special_case(char **map, int height)
{
    if (height == 1) {
        map = case_height_equal_one(map);
        my_printf("%s\n", map[0]);
        return 1;
    }
    return 0;
}
