/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
