/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_casesensitive
*/

#include "my.h"

char *my_casesensitive(char *str)
{
    int i = 0;
    char *str2 = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i]) {
        str2[i] = str[i];
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str2[i] += 32;
        }
        i++;
    }
    return str2;
}
