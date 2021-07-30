/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** .
*/

#include "../include/mysh.h"

int my_strcmp(char *str_o, char *str_c)
{
    int i = 0;
    int result = 0;

    while ((str_o[i] == str_c[i]) && (str_o[i] != '\0') && (str_c[i] != '\0')) {
        i++;
    }
    result = str_o[i] - str_c[i];
    return (result);
}
