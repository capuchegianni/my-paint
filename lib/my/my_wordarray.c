/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** word_array
*/

#include "my.h"

int get_words(char *str)
{
    int words = 0;

    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == ' ' && (str[i + 1] != ' ' || str[i + 1] != '\n' ||
        str[i + 1] != '\t'))
            words++;
        if (str[i] == '\n' && (str[i + 1] != ' ' || str[i + 1] != '\n' ||
        str[i + 1] != '\t'))
            words++;
    }
    return (words);
}

int get_chars(char *str)
{
    int chars = 0;

    for (; str[chars] != '\0' ; chars++);

    return (chars);
}

char *clear_str(char *str)
{
    char *str2 = str;
    char *str3 = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    for (; str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ; i++);
    for (; str[i] ; i++, k++)
        str2[k] = str[i];
    str2[k] = '\0';
    str3 = malloc(sizeof(char) * my_strlen(str2) + 1);
    j = my_strlen(str2);
    for (; !str[j] || str[j] == ' ' || str[j] == '\t' || str[j] == '\n' ; j--);
    for (k = 0 ; j >= 0 ; j--, k++)
        str3[k] = str2[j];
    str3[k] = '\0';
    str3 = my_revstr(str3);
    return str3;
}

char **my_wordarray(char *str, int letter)
{
    char *str2 = clear_str(str);
    int words = get_words(str2);
    int chars = get_chars(str2);
    char **tab = malloc(sizeof(char *) * (words + 2));
    int i = 0, j = 0, k = 0;
    if (str == NULL)
        return NULL;
    for (; i <= words ; i++) {
        tab[i] = malloc(sizeof(char) * (chars + 1));
        for (; str2[j] == ' ' || str2[j] == letter || str2[j] == '\t' ; j++);
        for (; str2[j] && str2[j] != ' ' && str2[j] != letter &&
        str2[j] != '\t' ; j++, k++)
            tab[i][k] = str2[j];
        tab[i][k] = '\0';
        if (k == 0)
            i--, words--;
        k = 0;
    } tab[i] = NULL;
    return tab;
}
