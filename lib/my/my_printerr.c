/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-gianni.henriques
** File description:
** my_puterr
*/

#include <unistd.h>
#include "my.h"

void my_putcharerr(char c)
{
    write(1, &c, 1);
}

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return 84;
}

void disp_stdarge(const char *s, va_list *ap, int i)
{
    if (s[i + 1] == 'e')
        my_puterror(va_arg(*ap, char *));
}

void my_printerr(const char *format, ...)
{
    va_list ap;
    int n = my_strlen(format);

    va_start(ap, format);
    for (int i = 0 ; i < n ; i++) {
        if (format[i] != '%')
            my_putcharerr(format[i]);
        else {
            disp_stdarge(format, &ap, i);
            i++;
        }
    }
    va_end(ap);
}
