/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    dest = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
