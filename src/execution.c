/*
** EPITECH PROJECT, 2021
** execution
** File description:
** .
*/

#include <mysh.h>

void executable(char **argv, List *my_env)
{
    int i = 0;
    int pr = 0;
    char *tmp = malloc(sizeof(char)*500);
    char *test = malloc(sizeof(char)*500);
    char **new = my_env->path;

    while (new[i]) {
        tmp = my_strcat(my_strdup("/"), my_strdup(argv[0]));
        test = my_strcat(my_strdup(new[i]), tmp);
        if (access(test, X_OK) == 0) {
            processe(test, my_env->env, argv);
            pr++;
        }
        if (pr > 0)
            return;
        i++;
    }
}

void processe(char *path, char **env, char **argv)
{
    pid_t pid = fork();
    int	status;

    if (pid == -1)
        return;
    if (pid == 0)
        execve(path, argv, env);
    else
        waitpid(pid, &status, 0);
}