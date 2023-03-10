/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** menu
*/

#include "../../include/header.h"

void display_menu(sfRenderWindow *window, filemenu_t *filemenu,
editionmenu_t *editionmenu, helpmenu_t *helpmenu)
{
    sfRenderWindow_drawRectangleShape(window, filemenu->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, editionmenu->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, helpmenu->rect, NULL);
    sfRenderWindow_drawText(window, filemenu->text, NULL);
    sfRenderWindow_drawText(window, editionmenu->text, NULL);
    sfRenderWindow_drawText(window, helpmenu->text, NULL);
}
