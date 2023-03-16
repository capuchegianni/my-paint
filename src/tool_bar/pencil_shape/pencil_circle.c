/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** pencil_circle
*/

#include "../../../include/header.h"

void click_pencilcircle(tool_bar_t *bar)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        bar->pencil_shape->circle->clicked = 1;
        sfRectangleShape_setFillColor(bar->pencil_shape->circle->out,
        sfColor_fromRGB(169, 169, 169));
        return;
    }
    if (bar->pencil_shape->circle->clicked == 1) {
        tools->pencil->shape = 0;
        bar->pencil_shape->circle->clicked = 0;
    }
}

void hover_pencilcircle(tool_bar_t *bar)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = bar->pencil_shape->circle->pos;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds
    (bar->pencil_shape->circle->out);
    sfVector2f button_size = bar->pencil_shape->circle->size;
    button_pos.x -= button_size.x / 2;
    button_pos.y -= button_size.y / 2;
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;
    if (sfFloatRect_contains(&rect, (mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)) == sfTrue) {
        sfRectangleShape_setFillColor(bar->pencil_shape->circle->out,
        sfColor_fromRGB(181, 181, 181));
        click_pencilcircle(bar);
    } else {
        sfRectangleShape_setFillColor(bar->pencil_shape->circle->out,
        bar->pencil_shape->circle->color);
    }
}
