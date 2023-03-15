/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-antman-gianni.henriques
** File description:
** my_nbrtostr
*/

#include "my.h"

int len_nbr(int nbr)
{
    int i = 0;

    if (nbr < 0)
        nbr *= -1;

    while (nbr > 0) {
        nbr /= 10;
        i++;
    }
    return (i);
}

char *my_tostr(int nb)
{
    int i = len_nbr(nb), x = 0, power = 0, cop = 0;
    char *result = malloc(sizeof(char) * (i + 1));
    if (nb == 0)
        return ("0");
    if (nb < 0) {
        result[x] = '-';
        x++;
        nb *= -1;
        power--;
        i++;
    }
    cop = nb;
    power += i;
    for (; x < i ; x++) {
        result[x] = (nb % my_pow(10, power))
        / my_pow(10, power - 1) + '0';
        power--;
    }
    result[i] = '\0';
    return (result);
}
