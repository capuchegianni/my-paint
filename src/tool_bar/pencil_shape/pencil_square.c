/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** pencil_square
*/

#include "../../../include/header.h"

void click_pencilsquare(tool_bar_t *bar)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        bar->pencil_shape->square->clicked = 1;
        sfRectangleShape_setFillColor(bar->pencil_shape->square->out,
        sfColor_fromRGB(169, 169, 169));
        return;
    }
    if (bar->pencil_shape->square->clicked == 1) {
        tools->pencil->shape = 1;
        bar->pencil_shape->square->clicked = 0;
    }
}

void hover_pencilsquare(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = bar->pencil_shape->square->pos;
    sfVector2f button_size = bar->pencil_shape->square->size;
    button_pos.x -= button_size.x / 2;
    button_pos.y -= button_size.y / 2;
    if (mouse_pos.x >= button_pos.x &&
    mouse_pos.x <= button_pos.x + button_size.x &&
    mouse_pos.y >= button_pos.y &&
    mouse_pos.y <= button_pos.y + button_size.y) {
        sfRectangleShape_setFillColor(bar->pencil_shape->square->out,
        sfColor_fromRGB(181, 181, 181));
        click_pencilsquare(bar);
    } else {
        sfRectangleShape_setFillColor(bar->pencil_shape->square->out,
        bar->pencil_shape->square->color);
    }
}
