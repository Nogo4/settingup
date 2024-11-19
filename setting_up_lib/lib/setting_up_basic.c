/*
** EPITECH PROJECT, 2024
** G1 - Unix System Programming
** File description:
** setting up project
*/

#include "../../lib/include/my.h"
#include "include/lib_setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int has_an_obstalce_in_the_line(char **map, int x, int y, int size)
{
    for (int i = x; i < x + size; i++) {
        if (map[y][i] == 'o' || map[y][i] == '\0'
            || map[y][i] == '\n')
            return 0;
    }
    return 1;
}

static int is_square_of_size(char **map_x_y, int x, int y, int size)
{
    for (int i = y; i < y + size; i++) {
        if (has_an_obstalce_in_the_line(map_x_y, x,
            i, size) == 0)
            return 0;
    }
    return 1;
}

static int value_of_square(char **map, int x, int y, int square)
{
    while (is_square_of_size(map, x, y, square + 1) == 1) {
        square++;
    }
    return square;
}

int pos_biggest_square(char **map, int *pos_bsq, int height)
{
    int y = 0;
    int x = 0;
    int square = 0;
    int clone_square = 0;

    while (y != height) {
        clone_square = square;
        square = value_of_square(map, x, y, square);
        if (square > clone_square) {
            pos_bsq[0] = y;
            pos_bsq[1] = x;
        }
        x++;
        if (map[y][x] == '\0') {
            x = 0;
            y++;
        }
    }
    return square;
}

char **edit_map_with_bsq(int y, int x, int square, char **map)
{
    int i = 0;

    for (i = 0; i != square; i++) {
        for (int i2 = 0; i2 != square; i2++) {
            map[y + i][x + i2] = 'x';
        }
    }
    return map;
}

void find_biggest_square(char *buffer, int height)
{
    char **map_x_y = my_str_to_word_array(buffer);
    int pos_bsq[] = {0, 0};
    int square = pos_biggest_square(map_x_y, pos_bsq, height);

    my_printf("%d\n", square);
    map_x_y = edit_map_with_bsq(pos_bsq[0], pos_bsq[1], square, map_x_y);
    for (int i = 0; i <= height; i++)
        my_printf("%s\n", map_x_y[i]);
    free(map_x_y);
}
