/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** square_shape
*/

#include "../../include/header.h"

void draw_square_two(sfVector2i mouse_pos, sfVector2f area_pos,
unsigned y, double x_ratio)
{
    for (unsigned i = 0,
    x = ((mouse_pos.x / x_ratio) - area_pos.x - tools->current_tool->size)
    / area->scale.x;
    i <= (unsigned)(tools->current_tool->size * 2) ; x++, i++) {
        if (x < area->img_size.x)
            sfImage_setPixel(area->image, x, y, tools->current_tool->color);
    }
}

void draw_square(sfVector2i mouse_pos, sfVector2f area_pos,
double y_ratio, double x_ratio)
{
    for (unsigned i = 0 ,
    y = ((mouse_pos.y / y_ratio) - area_pos.y - tools->current_tool->size)
    / area->scale.y;
    i <= (unsigned)(tools->current_tool->size * 2) ; y++, i++) {
        if (y < area->img_size.y) {
            draw_square_two(mouse_pos, area_pos, y, x_ratio);
        }
    }
    sfTexture_updateFromImage(area->texture, area->image, 0, 0);
}
