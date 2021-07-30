/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** .
*/

#include "../include/mysh.h"

char *my_strdup(char *str)
{
    int len = 0;
    char *dup = NULL;

    len = my_strlen(str) + 1;
    dup = malloc(sizeof(char) * len);
    if (!dup)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}