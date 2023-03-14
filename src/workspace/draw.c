/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** draw
*/

#include "../../include/header.h"

void draw_three(sfVector2i mouse_pos, sfVector2f area_pos, unsigned y)
{
    for (unsigned i = 0,
    x = (mouse_pos.x - area_pos.x - tools->current_tool->size) / area->scale.x;
    i <= (unsigned)(tools->current_tool->size * 2) ; x++, i++) {
        if (x < area->img_size.x)
            sfImage_setPixel(area->image, x, y, tools->current_tool->color);
    }
}

void draw_two(sfVector2i mouse_pos, sfVector2f area_pos)
{
    for (unsigned i = 0 ,
    y = (mouse_pos.y - area_pos.y - tools->current_tool->size) / area->scale.y;
    i <= (unsigned)(tools->current_tool->size * 2) ; y++, i++) {
        if (y < area->img_size.y) {
            draw_three(mouse_pos, area_pos, y);
        }
    }
    sfTexture_updateFromImage(area->texture, area->image, 0, 0);
}

void draw(void)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f area_pos = sfSprite_getPosition(area->sprite);

    if (mouse_pos.x > area_pos.x &&
    mouse_pos.x < area_pos.x + area->img_size.x * area->scale.x &&
    mouse_pos.y > area_pos.y &&
    mouse_pos.y < area_pos.y + area->img_size.y * area->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            draw_two(mouse_pos, area_pos);
        }
    }
}
