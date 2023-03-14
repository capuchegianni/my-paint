/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_print_text
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_csfml.h"

int my_print_text(sfRenderWindow *window, int size, sfVector2f pos, char *txt)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/other_font.ttf");

    if (text == NULL || font == NULL)
        return 1;
    sfText_setString(text, txt);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    return 0;
}
