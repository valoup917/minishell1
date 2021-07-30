/*
** EPITECH PROJECT, 2021
** unsetenv
** File description:
** .
*/

#include <mysh.h>

static int check_there(List *my_env, char *str)
{
    for (int i = 0; my_env->env[i]; i++) {
        if (my_strncmp(str, my_env->env[i], (my_strlen(str))) == 0)
            return 1;
    }
    return 0;
}

void unsetenv_cmd(List *my_env, char *str)
{
    int i = 0;
    int n = 0;
    char **test = new_env(my_env->env);
    char *token = strtok(my_strdup(test[i]), "=");

    if (check_there(my_env, str) == 0)
        return;
    while (my_strcmp(str, token) != 0) {
        i++;
        token = strtok(my_strdup(test[i]), "=");
    }
    for (n = i; my_env->env[n + 1]; n++) {
        my_env->env[n] = my_env->env[n + 1];
    }
    my_env->env[n] = NULL;
}