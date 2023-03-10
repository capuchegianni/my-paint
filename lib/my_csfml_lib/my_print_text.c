/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_print_text
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_csfml.h"

int my_print_text(sfRenderWindow *window, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/Aero-03.ttf");
    char *str = "POUET POUET";
    sfVector2u frame_size = sfRenderWindow_getSize(window);
    int print_mid_x = frame_size.x / 2;
    int print_mid_y = frame_size.y / 2;
    sfVector2f pos = {print_mid_x, print_mid_y};

    if (text == NULL || font == NULL)
        return 84;
    sfRenderWindow_clear(window, sfBlack);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    return 0;
}
