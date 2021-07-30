/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** .
*/

#include "../include/mysh.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int my_strlen2(char const *str)
{
    int i = 0;

    for (; str[i] != '\0' || str[i] != '\n'; i++);
    return (i);
}