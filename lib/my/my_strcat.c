/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (j + my_strlen(src)) + 1);

    for (int j = 0 ; dest[j] ; j++)
        tmp[j] = dest[j];
    for (; src[i] ; i++) {
        tmp[i + j] = src[i];
    }
    tmp[i + j] = '\0';
    return tmp;
}
