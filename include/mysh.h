/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


typedef struct Liste
{
    char **env;
    char **path;
}List;

/*LIB*/
char *clear_str(const char *str);
void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char *str);
char *my_strcat(char *dest, char *src);
char *my_strcat2(char *dest, char *src);
int my_strcmp(char *str_o, char *str_c);
char *my_strcpy(char *dest, char const *src);
char *my_strcpy2(char *dest, char const *src);
char *my_strdup(char *str);
int my_strlen(char const *str);
int my_strlen2(char const *str);
int nbr_letters(char *str, int rank);
int my_strncmp(char *s1, char *s2, int n);
int is_good(char c);
int nb_words(char *str);

/*SRC -builtins*/
void exit_cmd(List *my_env);
void cd_cmd(char **argv, List *my_env);
void env_cmd(List *my_env);
void setenv_cmd(List *my_env, char **argv);
void unsetenv_cmd(List *my_env, char *str);

/*SRC -main*/
void my_bash(char **argv, char **env);
int my_bultins(char *str, List *my_env, char **argv);
void path_add(List *my_env, char **env);
void free_all(List *my_env);
char **new_env(char **env);

/*SRC -execution*/
void executable(char **argv, List *my_env);
void processe(char *path, char **env, char **argv);

/* priorities.c */
int check_ms2(char **argv, List *my_env);

/* manage cd */
void move_old(List *my_env);
char *home_env(List *my_env);
char *old_pwd(List *my_env);
int count_arg(char **argv);