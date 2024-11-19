/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-setting_up-noah.gomes
** File description:
** lib_my_ls
*/

#ifndef INCLUDED_LIB_SETTING_UP_H
    #define INCLUDED_LIB_SETTING_UP_H
    #include <dirent.h>
int count_x(char *buffer, int i);
int skip_height(char *buffer);
int count_y(char *buffer);
int my_getnbr(char const *str);
int test_is_valid_file(int test_buf);
int is_valid_map(char *buffer);
int my_argc(char **av);
char **my_str_to_word_array(char *str);
void find_biggest_square(char *buffer, int height);
int special_case(char **map, int height);

#endif
