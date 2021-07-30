/*
** EPITECH PROJECT, 2021
** priorities.c
** File description:
** .
*/

#include <mysh.h>

void separate_semi(char **argv, List *my_env)
{
    char **tmp = malloc(sizeof(char *) * 20);
    int a = 0;
    for (int i = 0; argv[i]; i++) {

        if (my_strcmp(argv[i], ";") == 0) {

            tmp[a + 1] = NULL;
            executable(tmp, my_env);
            a = 0;
            tmp = malloc(sizeof(char *) * 20);
        }
        else {
            tmp[a] = argv[i];
            a++;
        }

    }
    tmp[a + 1] = NULL;
    executable(tmp, my_env);
}

int check_ms2(char **argv, List *my_env)
{
    for (int i = 0; argv[i];i++) {
        if (my_strcmp(argv[i], ";") == 0) {
            separate_semi(argv, my_env);
            return 1;
        }
    }
    return 0;
}