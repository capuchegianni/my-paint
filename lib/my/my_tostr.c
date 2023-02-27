/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-antman-gianni.henriques
** File description:
** my_nbrtostr
*/

#include "my.h"

int nbr(int cop, int i)
{
    while (cop > 0) {
        cop /= 10;
        i++;
    }
    return i;
}

char *convert(int y, int x, int cop, int nb)
{
    int i = 0;
    int power = 0;
    char *result = malloc(sizeof(char) * 1000);

    if (cop == 0) {
        result[x] = '0';
        return result;
    }
    i = nbr(cop, i);
    power = i;
    for (; x < i + y ; x++) {
        result[x] = (nb % my_pow(10, power))
        / my_pow(10, power - 1) + '0';
        power--;
    }
    return (result);
}

char *my_tostr(int nb)
{
    int x = 0;
    int y = 0;
    int cop = nb;
    char *neg = malloc(sizeof(char) * 2);
    char *result = malloc(sizeof(char) * 1000);

    if (cop < 0) {
        cop *= -1;
        nb *= -1;
        neg[x] = '-';
    }
    result = convert(y, x, cop, nb);
    result = my_strcat(neg, result);
    return result;
}
