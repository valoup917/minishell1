/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include <mysh.h>

int main(int argc, char *argv[], char **env)
{
    if (argc != 1)
        exit(84);
    my_bash(argv, env);
    return 0;
}

void my_bash(char **argv, char **env)
{
    int size = 0;
    char *line = NULL;
    List *my_env = malloc(sizeof(List));

    my_env->env = new_env(env);
    size_t len = 0;
    path_add(my_env, env);
    my_putstr("$>");
    while ((size = getline(&line, &len, stdin)) != -1) {
        line[size - 1] = '\0';
        path_add(my_env, env);
        line = clear_str(line);
        argv = my_str_to_word_array(line);
        if (check_ms2(argv, my_env) == 1)
            1 + 1;
        else if (my_bultins(line, my_env, argv) == 0)
            executable(argv, my_env);
        my_putstr("$>");
    }
}

void path_add(List *my_env, char **env)
{
    int x = 0;
    int count = 0;
    char *token;
    int w = 0;

    for (;env[x][0] != 'P' || env[x][1] != 'A' || env[x][2] != 'T'
    || env[x][3] != 'H' || env[x][4] != '='; x++);
    token = env[x] + 5;
    for (int n = 0; token[n] != '\0'; n++) {
        if (token[n] == ':')
            count++;
    }
    my_env->path = malloc(sizeof(char *) * (count + 2));
    for (; w <= count; w++) {
        token = strtok(my_strdup(token), ":");
        my_env->path[w] = malloc(sizeof(char)* (my_strlen(token) + 1));
        my_env->path[w] = token;
        my_env->path[w][my_strlen(token)] = '\0';
        token = strtok(NULL, " ");
    }
    my_env->path[w] = NULL;
}

int my_bultins(char *str, List *my_env, char **argv)
{
    if (my_strcmp(str, "exit") == 0)
        exit_cmd(my_env);
    if (my_strcmp(argv[0], "cd") == 0) {
        cd_cmd(argv, my_env);
        return 1;
    }
    if (my_strcmp(str, "env") == 0) {
        env_cmd(my_env);
        return 1;
    }
    if (my_strcmp(argv[0], "setenv") == 0) {
        setenv_cmd(my_env, argv);
        return 1;
    }
    if (my_strcmp(argv[0], "unsetenv") == 0) {
        unsetenv_cmd(my_env, argv[1]);
        return 1;
    }
    return 0;
}

void free_all(List *my_env)
{
    for (int i = 0; my_env->path[i]; i++) {
        free(my_env->path[i]);
    }
    free(my_env->path);
    free(my_env);
}