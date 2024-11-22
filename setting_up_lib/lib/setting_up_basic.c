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

static int check_full_size(char **map, int y, int square)
{
    int max_size = my_argc(map) - 2;

    if (y + square > max_size)
            return 1;
    return 0;
}

int pos_biggest_square(char **map, int *pos_bsq, int height, int is_generated)
{
    int vector[] = {0, 0};
    int square = 0;
    int clone_square = 0;

    while (vector[0] != height) {
        clone_square = square;
        if (is_generated == 1 && check_full_size(map, vector[0], square) == 1)
            return square;
        square = value_of_square(map, vector[1], vector[0], square);
        if (square > clone_square) {
            pos_bsq[0] = vector[0];
            pos_bsq[1] = vector[1];
        }
        vector[1] += 1;
        if (map[vector[0]][vector[1]] == '\0') {
            vector[1] = 0;
            vector[0] += 1;
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

static void write_with_generated_map(int height, char **map)
{
    int i = 0;
    char back_line = '\n';

    for (; i != height; i++) {
            write(1, map[i], my_strlen(map[i]));
            write(1, &back_line, 1);
    }
    write(1, map[i], my_strlen(map[i]));
}

static void free_all(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map);
}

void find_biggest_square(char *buffer, int height,
    int generated_map)
{
    char **map_x_y = my_str_to_word_array(buffer);
    int pos_bsq[] = {0, 0};
    int square = 0;
    char back_line = '\n';

    if (special_case(map_x_y, height) == 1)
        return;
    square = pos_biggest_square(map_x_y, pos_bsq, height, generated_map);
    map_x_y = edit_map_with_bsq(pos_bsq[0], pos_bsq[1], square, map_x_y);
    if (generated_map == 0) {
        for (int i = 0; i <= height; i++) {
            write(1, map_x_y[i], my_strlen(map_x_y[i]));
            write(1, &back_line, 1);
        }
    }
    if (generated_map == 1) {
        write_with_generated_map(height, map_x_y);
        free(buffer);
    }
    free_all(map_x_y);
}
