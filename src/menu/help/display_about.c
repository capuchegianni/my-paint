/*
** EPITECH PROJECT, 2023
** my-paint_gianni
** File description:
** display_about
*/

#include "../../../include/header.h"

void display_about(char *login1, char *login2, buttonmenu_t *back)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f rect_size = {1920, 100};
    sfVector2f rect_pos = {0, 0};
    sfRectangleShape_setSize(rect, rect_size);
    sfRectangleShape_setPosition(rect, rect_pos);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(194, 194, 194));
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    my_print_text(window, 30, (sfVector2f){30, 10}, login1);
    my_print_text(window, 30, (sfVector2f){30, 50}, login2);
    sfRenderWindow_drawRectangleShape(window, back->rect, NULL);
    sfRenderWindow_drawText(window, back->text, NULL);
    sfRenderWindow_display(window);
}
