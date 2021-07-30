/*
** EPITECH PROJECT, 2021
** clear_str.c
** File description:
** .
*/

#include <mysh.h>

static int nbr_in_words(const char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            nbr += 1;
            while (str[i] == ' ' || str[i] == '\t')
                i++;
        }
    }
    nbr += 1;
    return nbr;
}

char *clear_str(const char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str)+1);
    unsigned int a = 0;
    unsigned int words = nbr_in_words(str);

    for (int i = 0;str[i];i++) {
        if (str[i] == '\t')
            continue;
        else {
            if (i != 0 && str[i] == ';' && str[i-1] != ' ') {
                new[a] = ' ';
                new[a + 1] = ';';
                a++;
            }
            if (str[i] == '\t')
                new[a] = ' ';
            else
                new[a] = str[i];
            a++;
        }
    }
    new[my_strlen(str)] = '\0';
    printf("str = %s\n", new);
    return new;
}