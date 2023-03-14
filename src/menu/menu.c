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

void display_bar(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f rect_size = {1920, 50};
    sfVector2f rect_pos = {0, 0};

    sfRectangleShape_setSize(rect, rect_size);
    sfRectangleShape_setPosition(rect, rect_pos);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(194, 194, 194));
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
}
