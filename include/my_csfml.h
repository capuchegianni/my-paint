/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my
*/

#ifndef MY_LIB_CSFML_H_
    #define MY_LIB_CSFML_H_

    #include <SFML/Graphics.h>

    int my_close_window(sfRenderWindow *window);
    int my_window_too_small(sfRenderWindow *window, int width, int height);
    int my_print_text(sfRenderWindow *window, int size);
    int my_background(sfRenderWindow *window);
    int my_animated_sprite(sfRenderWindow *window, int i);
    void my_click_sprite(sfRenderWindow *window, sfSprite *sprite, int i);

#endif /* MY_LIB_CSFML_H_ */
