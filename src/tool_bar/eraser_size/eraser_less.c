/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** eraser_less
*/

#include "../../../include/header.h"

void click_eraserless(tool_bar_t *bar)
{
    if (bar->eraser_size->less->clicked == 1 && bar->eraser_size->nbr > 1) {
        bar->eraser_size->nbr--;
        tools->eraser->size = bar->eraser_size->nbr;
        char *strnbr = my_tostr(bar->eraser_size->nbr);
        sfText_setString(bar->eraser_size->tnbr, strnbr);
        sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){120, 405});
        if (bar->eraser_size->nbr > 9)
            sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){115, 405});
        if (bar->eraser_size->nbr > 99)
            sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){110, 405});
        bar->eraser_size->less->clicked = 0;
    }
}

void hover_eraserless(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfFloatRect infos =
    sfRectangleShape_getGlobalBounds(bar->eraser_size->less->rect);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;
    if (sfFloatRect_contains(&infos, (mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)) == sfTrue) {
        sfRectangleShape_setFillColor(bar->eraser_size->less->rect,
        sfColor_fromRGB(181, 181, 181));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            bar->eraser_size->less->clicked = 1;
            sfRectangleShape_setFillColor(bar->eraser_size->less->rect,
            sfColor_fromRGB(169, 169, 169));
            return;
        } click_eraserless(bar);
    } else {
        sfRectangleShape_setFillColor(bar->eraser_size->less->rect,
        bar->eraser_size->less->color);
    }
}
