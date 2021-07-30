/*
** EPITECH PROJECT, 2021
** setenv
** File description:
** .
*/

#include <mysh.h>

static int already_here(List *my_env, char **argv)
{
    int a = 0;
    int i = 0;
    char *new = my_strcat(argv[1], "=");

    for (; my_env->env[i]; i++) {
        if (my_strncmp(my_env->env[i], argv[1], my_strlen(argv[1])) == 0) {
            a = 1;
            break;
        }
    }
    if (a == 0)
        return 0;
    my_env->env[i] = malloc(sizeof(char)*my_strlen(argv[1])
    + 1 + my_strlen(argv[2]) + 1);
    new = my_strcat(new, argv[2]);
    my_env->env[i] = new;
    return 1;
}

void setenv_cmd(List *my_env, char **argv)
{
    int i = 0;

    if (argv[1] == NULL) {
        env_cmd(my_env);
        return;
    }
    if (already_here(my_env, argv) == 1)
        return;
    for (;my_env->env[i] != NULL;i++);
    if (argv[2] == NULL)
        my_env->env[i] = malloc(sizeof(char)*my_strlen(argv[1])+1);
    else
        my_env->env[i] = malloc(sizeof(char)*my_strlen(argv[1]) +
        1 + my_strlen(argv[2]) + 1);
    my_strcpy(my_env->env[i], argv[1]);
    my_env->env[i] = my_strcat(my_env->env[i], "=");
    if (argv[2] != NULL)
        my_env->env[i] = my_strcat(my_env->env[i], argv[2]);
    my_env->env[i+1] = NULL;
}