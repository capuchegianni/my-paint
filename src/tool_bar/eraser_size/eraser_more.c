/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** eraser_more
*/

#include "../../../include/header.h"

void click_erasermore(tool_bar_t *bar)
{
    if (bar->eraser_size->more->clicked == 1 && bar->eraser_size->nbr < 100) {
        bar->eraser_size->nbr++;
        tools->eraser->size = bar->eraser_size->nbr;
        char *strnbr = my_tostr(bar->eraser_size->nbr);
        sfText_setString(bar->eraser_size->tnbr, strnbr);
        sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){120, 380});
        if (bar->eraser_size->nbr > 9)
            sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){115, 380});
        if (bar->eraser_size->nbr > 99)
            sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){105, 380});
        bar->eraser_size->more->clicked = 0;
    }
}

void hover_erasermore(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfFloatRect infos =
    sfRectangleShape_getGlobalBounds(bar->eraser_size->more->rect);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;
    if (sfFloatRect_contains(&infos, (mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)) == sfTrue) {
        sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
        sfColor_fromRGB(181, 181, 181));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            bar->eraser_size->more->clicked = 1;
            sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
            sfColor_fromRGB(169, 169, 169));
            sfSleep(sfMilliseconds(150));
        } click_erasermore(bar);
    } else {
        sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
        bar->eraser_size->more->color);
    }
}
