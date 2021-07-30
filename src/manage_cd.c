/*
** EPITECH PROJECT, 2021
** manage cd
** File description:
** .
*/

#include <mysh.h>

int count_arg(char **argv)
{
    int i = 0;

    for (;argv[i];i++);
    return i;
}

char *old_pwd(List *my_env)
{
    char **tmp = my_env->env;
    char *str;
    int x = 0;

    for (;tmp[x][0] != 'O' || tmp[x][1] != 'L' || tmp[x][2] != 'D'
    || tmp[x][3] != 'P' || tmp[x][4] != 'W' || tmp[x][5] != 'D'; x++);
    str = tmp[x] + 7;
    return str;
}

char *home_env(List *my_env)
{
    char **tmp = my_env->env;
    char *str;
    int x = 0;

    for (;tmp[x][0] != 'H' || tmp[x][1] != 'O' || tmp[x][2] != 'M'
    || tmp[x][3] != 'E' || tmp[x][4] != '='; x++);
    str = tmp[x] + 5;
    return str;
}

void move_old(List *my_env)
{
    char *str = getcwd(NULL, 0);
    int x = 0;

    str = my_strcat(my_strdup("OLDPWD="), str);

    for (; my_env->env[x][0] != 'O' || my_env->env[x][1] != 'L'
    || my_env->env[x][2] != 'D'
    || my_env->env[x][3] != 'P' || my_env->env[x][4] != 'W'
    || my_env->env[x][5] != 'D'; ++x);
    my_env->env[x] = malloc(sizeof(char) * my_strlen(str) + 1);
    my_strcpy(my_env->env[x], str);
}