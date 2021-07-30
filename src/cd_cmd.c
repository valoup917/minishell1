/*
** EPITECH PROJECT, 2021
** manage cd
** File description:
** .
*/

#include <mysh.h>

static void cd_one_arg(List *my_env)
{
    move_old(my_env);
    chdir(home_env(my_env));
    return;
}

static void cd_two_arg(char **argv, List *my_env)
{
    char *str;

    if (my_strcmp(argv[1], "-") == 0) {
        str = old_pwd(my_env);
        move_old(my_env);
        chdir(str);
        return;
    }
    move_old(my_env);
    if (my_strcmp(argv[1], "~") == 0)
        chdir(home_env(my_env));
    else if (chdir(argv[1]) == -1)
        perror(argv[1]);
}

void cd_cmd(char **argv, List *my_env)
{
    int argc = count_arg(argv);

    if (argc > 2)
        my_putstr("cd: too many arguments\n");
    if (argc == 1)
        cd_one_arg(my_env);
    else if (argc == 2)
        cd_two_arg(argv, my_env);
}