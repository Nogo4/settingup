/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-settingup-noah.gomes
** File description:
** functions to find if is a good file and good map for setting up project
*/

#include "../../../lib/include/my.h"
#include "../include/lib_setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int test_is_valid_file(int test_buf)
{
    if (test_buf == -1)
        return 1;
    return 0;
}

int search_if_get_char_wrong(char *buffer, int i)
{
    while (buffer[i] != '\0') {
        if (buffer[i] != '\n' && buffer[i] != '.' && buffer[i] != 'o')
            return 1;
        i++;
    }
    return 0;
}

int is_valid_map(char *buffer)
{
    int height_given_by_file = my_getnbr(buffer);
    int y_height = count_y(buffer);
    int i_skip = skip_height(buffer);
    int width = count_x(buffer, i_skip);
    int real_size = my_strlen(buffer) - y_height - i_skip;
    int good_size = width * y_height;

    if (height_given_by_file != y_height)
        return 1;
    if (search_if_get_char_wrong(buffer, i_skip) == 1)
        return 1;
    if (good_size != real_size)
        return 1;
    return 0;
}
