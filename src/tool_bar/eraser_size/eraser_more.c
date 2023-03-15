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
        sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){120, 405});
        if (bar->eraser_size->nbr > 9)
            sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){115, 405});
        if (bar->eraser_size->nbr > 99)
            sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){105, 405});
        bar->eraser_size->more->clicked = 0;
    }
}

void hover_erasermore(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = bar->eraser_size->more->pos;
    sfVector2f button_size = bar->eraser_size->more->size;
    if (mouse_pos.x >= button_pos.x &&
    mouse_pos.x <= button_pos.x + button_size.x &&
    mouse_pos.y >= button_pos.y &&
    mouse_pos.y <= button_pos.y + button_size.y) {
        sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
        sfColor_fromRGB(181, 181, 181));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            bar->eraser_size->more->clicked = 1;
            sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
            sfColor_fromRGB(169, 169, 169));
            return;
        }
        click_erasermore(bar);
    } else {
        sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
        bar->eraser_size->more->color);
    }
}
