/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** eraser_circle
*/

#include "../../../include/header.h"

void click_erasercircle(tool_bar_t *bar)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        bar->eraser_shape->circle->clicked = 1;
        sfRectangleShape_setFillColor(bar->eraser_shape->circle->out,
        sfColor_fromRGB(169, 169, 169));
        return;
    }
    if (bar->eraser_shape->circle->clicked == 1) {
        tools->eraser->shape = 0;
        bar->eraser_shape->circle->clicked = 0;
    }
}

void hover_erasercircle(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = bar->eraser_shape->circle->pos;
    sfVector2f button_size = bar->eraser_shape->circle->size;
    button_pos.x -= button_size.x / 2;
    button_pos.y -= button_size.y / 2;
    if (mouse_pos.x >= button_pos.x &&
    mouse_pos.x <= button_pos.x + button_size.x &&
    mouse_pos.y >= button_pos.y &&
    mouse_pos.y <= button_pos.y + button_size.y) {
        sfRectangleShape_setFillColor(bar->eraser_shape->circle->out,
        sfColor_fromRGB(181, 181, 181));
        click_erasercircle(bar);
    } else {
        sfRectangleShape_setFillColor(bar->eraser_shape->circle->out,
        bar->eraser_shape->circle->color);
    }
}
