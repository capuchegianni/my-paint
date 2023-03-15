/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** more
*/

#include "../../../include/header.h"

void click_pencilmore(tool_bar_t *bar)
{
    if (bar->pencil_size->more->clicked == 1 && bar->pencil_size->nbr < 100) {
        bar->pencil_size->nbr++;
        tools->pencil->size = bar->pencil_size->nbr;
        char *strnbr = my_tostr(bar->pencil_size->nbr);
        sfText_setString(bar->pencil_size->tnbr, strnbr);
        sfText_setPosition(bar->pencil_size->tnbr, (sfVector2f){120, 280});
        if (bar->pencil_size->nbr > 9)
            sfText_setPosition(bar->pencil_size->tnbr, (sfVector2f){115, 280});
        if (bar->pencil_size->nbr > 99)
            sfText_setPosition(bar->pencil_size->tnbr, (sfVector2f){105, 280});
        bar->pencil_size->more->clicked = 0;
    }
}

void hover_pencilmore(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = bar->pencil_size->more->pos;
    sfVector2f button_size = bar->pencil_size->more->size;
    if (mouse_pos.x >= button_pos.x &&
    mouse_pos.x <= button_pos.x + button_size.x &&
    mouse_pos.y >= button_pos.y &&
    mouse_pos.y <= button_pos.y + button_size.y) {
        sfRectangleShape_setFillColor(bar->pencil_size->more->rect,
        sfColor_fromRGB(181, 181, 181));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            bar->pencil_size->more->clicked = 1;
            sfRectangleShape_setFillColor(bar->pencil_size->more->rect,
            sfColor_fromRGB(169, 169, 169));
            sfSleep(sfMilliseconds(150));
        }
        click_pencilmore(bar);
    } else {
        sfRectangleShape_setFillColor(bar->pencil_size->more->rect,
        bar->pencil_size->more->color);
    }
}
