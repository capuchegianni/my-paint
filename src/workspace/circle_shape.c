/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** circle_shape
*/

#include "../../include/header.h"

void draw_circle_two(int i, int j, int x, int y)
{
    int radius_squared = tools->current_tool->size * tools->current_tool->size;
    int dx = i - x;
    int dy = j - y;
    if (dx * dx + dy * dy - 1 <= radius_squared)
        sfImage_setPixel(area->image, i, j, tools->current_tool->color);
}

void draw_circle(sfVector2i mouse_pos, sfVector2f area_pos,
double y_ratio, double x_ratio)
{
    int x = ((mouse_pos.x / x_ratio) - area_pos.x) / area->scale.x;
    int y = ((mouse_pos.y / y_ratio) - area_pos.y) / area->scale.y;
    int x_min = x - tools->current_tool->size < 0 ? 0
    : x - tools->current_tool->size;
    int y_min = y - tools->current_tool->size < 0 ? 0
    : y - tools->current_tool->size;
    unsigned int x_max = x + tools->current_tool->size > (int)area->img_size.x ?
    (int)area->img_size.x : x + tools->current_tool->size;
    unsigned int y_max = y + tools->current_tool->size > (int)area->img_size.y ?
    (int)area->img_size.y : y + tools->current_tool->size;

    for (unsigned int j = y_min ; j < y_max ; j++) {
        for (unsigned int i = x_min ; i < x_max ; i++) {
            draw_circle_two(i, j, x, y);
        }
    }
    sfTexture_updateFromImage(area->texture, area->image, 0, 0);
}
