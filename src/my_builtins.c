/*
** EPITECH PROJECT, 2021
** my_builtins
** File description:
** .
*/

#include <mysh.h>

void env_cmd(List *my_env)
{
    int i = 0;

    while (my_env->env[i]) {
        my_putstr(my_env->env[i]);
        my_putchar('\n');
        i++;
    }
}

void exit_cmd(List *my_env)
{
    free_all(my_env);
    exit(0);
}