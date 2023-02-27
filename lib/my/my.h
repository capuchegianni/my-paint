/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    //basic functions

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <sys/signal.h>

    //SFML functions
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    char *my_casesensitive(char *str);
    int my_findprimesup(int nb);
    void my_free_wordarray(char **array);
    int my_getnbr(char const *str);
    int my_isneg(int nb);
    int my_isnum(char *str);
    int my_isprime(int nb);
    int my_pow(int nb, int p);
    void my_print(const char *format, ...);
    void my_putchar(char c);
    void my_printerr(const char *format, ...);
    int my_putfloat(double nbr);
    void my_putnbr(long long nb);
    int my_putstr(char const *str);
    char *my_readfile_stat(char *filepath);
    char *my_readfile_gl(char *filepath);
    char *my_revstr(char *str);
    void my_sortintarray(int *tab, int size);
    double my_sqrt(int nb);
    char *my_strcat(char *dest, char const *src);
    int my_cmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strstr(char *str, char const *to_find);
    int my_strisalpha(char *str);
    int my_strlen(char const *str);
    char *my_strncat(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    void my_swap(char *a, char *b);
    int my_tablen(char **tab);
    char *my_tostr(int nb);
    char **my_wordarray(char *str, int letter);

#endif /* MY_H_ */
