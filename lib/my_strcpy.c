/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** .
*/

#include "../include/mysh.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (;src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy2(char *dest, char const *src)
{
    int i = 0;

    for (;src[i] != '\0' || src[i] != '\n'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}