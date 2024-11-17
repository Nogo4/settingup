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

void create_map_xy(char *buffer)
{
    int i = skip_height(buffer);
    int y_size = count_y(buffer);
    char **map = malloc(sizeof(char) * (my_strlen(buffer) - i));

    is_valid_map(buffer);
}

int setting_up(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    struct stat buf_struct;
    int test_buf = stat(argv[1], &buf_struct);
    char *buffer = malloc(sizeof(char) * buf_struct.st_size + 1);
    int size = read(fd, buffer, buf_struct.st_size);

    buffer[buf_struct.st_size] = '\0';
    close(fd);
    if (test_is_valid_file(test_buf) == 1 || is_valid_map(buffer) == 1) {
        my_printf("Error file\n");
        return 84;
    }
    //create_map_xy(buffer);
    free(buffer);
    return 0;
}

int main(int argc, char **argv)
{
    return setting_up(argc, argv);
}
