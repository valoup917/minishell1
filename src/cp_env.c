/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include <mysh.h>

static int sizeofenv(char **env)
{
    int a = 0;

    for (; env[a]; a++);
    return a;
}

char **new_env(char **env)
{
    char **new = malloc(sizeof(char *) * sizeofenv(env));

    for (int i = 0; env[i]; i++)
        new[i] = my_strdup(env[i]);
    return new;
}