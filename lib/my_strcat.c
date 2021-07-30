/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** .
*/

#include "../include/mysh.h"

char *my_strcat(char *dest, char *src)
{
    int	i = my_strlen(dest);
    int i2 = my_strlen(src);
    int	j = 0;
    int x = 0;
    char *new = malloc(sizeof(char)*(i + i2 + 1));

    for (; x < (i + i2); x++) {
        if (x < i)
            new[x] = dest[x];
        else {
            new[x] = src[j];
            j++;
        }
    }
    new[x] = '\0';
    return new;
}