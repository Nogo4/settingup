/*
** EPITECH PROJECT, 2024
** G1 - Unix System Programming
** File description:
** setting up project
*/

#include "lib/include/my.h"
#include "setting_up_lib/lib/include/lib_setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int dont_need_to_generate(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    struct stat buf_struct;
    int test_buf = stat(argv[1], &buf_struct);
    char *buffer = malloc(sizeof(char) * buf_struct.st_size + 1);
    int size = read(fd, buffer, buf_struct.st_size);

    buffer[buf_struct.st_size] = '\0';
    close(fd);
    if (is_an_empty_file(buffer) == 1) {
        my_printf("Error file\n");
        return 84;
    }
    if (test_is_valid_file(test_buf) == 1 || is_valid_map(buffer) == 1) {
        my_printf("Error file\n");
        return 84;
    }
    find_biggest_square(buffer, my_getnbr(buffer) - 1);
    free(buffer);
    return 0;
}

int generate_map(char **argv)
{
    int len = my_getnbr(argv[1]) + 1;
    char *str = NULL;

    if (len <= 0)
        return 84;
}

int setting_up(int argc, char **argv)
{
    if (argc == 2)
        return dont_need_to_generate(argc, argv);
    if (argc == 3) {
        if (generate_map(argv) == 84)
            return 84;
        return 0;
    }
    return 84;
}

int main(int argc, char **argv)
{
    return setting_up(argc, argv);
}
