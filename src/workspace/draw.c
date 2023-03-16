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

void pick_three(sfVector2i mouse_pos, sfVector2f area_pos, unsigned y)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    double x_ratio = (double)window_size.x / 1920;

    for (unsigned i = 0,
    x = ((mouse_pos.x / x_ratio) - area_pos.x - tools->current_tool->size)
    / area->scale.x;
    i <= (unsigned)(tools->current_tool->size * 2) ; x++, i++) {
        if (x < area->img_size.x)
            (tools->current_tool != tools->eraser) ?
            tools->current_tool->color =
            sfImage_getPixel(area->image, x, y) : sfWhite;
    }
}

void pick_two(sfVector2i mouse_pos, sfVector2f area_pos)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    double y_ratio = (double)window_size.y / 1016;

    for (unsigned i = 0 ,
    y = ((mouse_pos.y / y_ratio) - area_pos.y - tools->current_tool->size)
    / area->scale.y;
    i <= (unsigned)(tools->current_tool->size * 2) ; y++, i++) {
        if (y < area->img_size.y) {
            pick_three(mouse_pos, area_pos, y);
        }
    }
    sfTexture_updateFromImage(area->texture, area->image, 0, 0);
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
        choose_cursor(x_ratio, y_ratio);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            circle_or_square(mouse_pos, area_pos, y_ratio, x_ratio);
        if (sfMouse_isButtonPressed(sfMouseRight))
            pick_two(mouse_pos, area_pos);
    } else
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
}
