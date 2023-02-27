/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (j + n) + 1);

    for (int j = 0 ; dest[j] ; j++)
        tmp[j] = dest[j];
    for (; i < n ; i++) {
        tmp[i + j] = src[i];
    }
    tmp[i + j] = '\0';
    return tmp;
}
