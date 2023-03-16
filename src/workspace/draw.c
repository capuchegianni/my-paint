/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** draw
*/

#include "../../include/header.h"

void circle_or_square(sfVector2i mouse_pos, sfVector2f area_pos,
double y_ratio, double x_ratio)
{
    if (tools->current_tool->shape == 0)
        draw_circle(mouse_pos, area_pos, y_ratio, x_ratio);
    else
        draw_square(mouse_pos, area_pos, y_ratio, x_ratio);
}

void draw(void)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f area_pos = sfSprite_getPosition(area->sprite);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;

    if ((mouse_pos.x / x_ratio) > area_pos.x &&
    (mouse_pos.x / x_ratio) < area_pos.x + area->img_size.x * area->scale.x &&
    (mouse_pos.y / y_ratio) > area_pos.y &&
    (mouse_pos.y / y_ratio) < area_pos.y + area->img_size.y * area->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            circle_or_square(mouse_pos, area_pos, y_ratio, x_ratio);
        }
    }
}
