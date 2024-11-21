/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>

static int is_alpha(char it)
{
    if (it == '.' || it == 'o')
        return 0;
    return 1;
}

static int skip_separate(char *str, int i)
{
    while (is_alpha(str[i]) == 1 && str[i] != '\0')
        i++;
    return i;
}

static int count_lign(char *str)
{
    int i = 0;
    int counter_lign = 0;

    while (str[i] != '\0') {
        if (is_alpha(str[i]) == 1) {
            i = skip_separate(str, i);
            counter_lign++;
        }
        if (str[i] != 0)
            i++;
    }
    return counter_lign;
}

static int word_length(char *str, int i)
{
    int counter = 0;

    while (is_alpha(str[i]) != 1 && str[i] != '\0') {
        counter++;
        i++;
    }
    return counter;
}

static char *fill_str(char *str, int i, char *fill_str)
{
    int i_str = 0;

    while (is_alpha(str[i]) != 1 && str[i] != '\0') {
        fill_str[i_str] = str[i];
        i_str++;
        i++;
    }
    fill_str[i_str] = '\0';
    return fill_str;
}

static int skip_word(char *str, int i)
{
    while (is_alpha(str[i]) == 0 && str[i] != '\0')
        i++;
    return i;
}

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int i_lign = 0;
    int nb_word = count_lign(str) + 1;
    char **word_array = malloc(sizeof(char *) * (nb_word + 1));
    int lenght_word = 0;

    for (; i_lign < nb_word; i_lign++) {
        i = skip_separate(str, i);
        lenght_word = word_length(str, i);
        word_array[i_lign] = malloc(sizeof(char) * lenght_word + 1);
        fill_str(str, i, word_array[i_lign]);
        i = skip_word(str, i);
    }
    word_array[i_lign] = NULL;
    return word_array;
}
