/*
** EPITECH PROJECT, 2023
** my-paint_gianni
** File description:
** tools_sprites
*/

#include "../../include/header.h"

void pencil_cursor(double x_ratio, double y_ratio)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.03, 0.03};

    sfSprite_setTexture(sprite, tools->pencil->texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
}

void eraser_cursor(double x_ratio, double y_ratio)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite *sprite = sfSprite_create();
    sfVector2u sprite_size = sfTexture_getSize(tools->eraser->texture);
    sfVector2f scale = {0.05, 0.05};

    sfSprite_setTexture(sprite, tools->eraser->texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setRotation(sprite, 90);
    sfSprite_setOrigin(sprite, (sfVector2f){sprite_size.x / 4,
    sprite_size.y - (sprite_size.y / 4)});
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
}

void bucket_cursor(double x_ratio, double y_ratio)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.05, 0.05};

    sfSprite_setTexture(sprite, tools->bucket->texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
}

void color_picker_cursor(double x_ratio, double y_ratio)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.05, 0.05};
    sfVector2u sprite_size = sfTexture_getSize(tools->color_picker->texture);

    sfSprite_setOrigin(sprite, (sfVector2f){0, sprite_size.y});
    sfSprite_setTexture(sprite, tools->color_picker->texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
}

void choose_cursor(double x_ratio, double y_ratio)
{
    if (tools->current_tool == tools->pencil)
        pencil_cursor(x_ratio, y_ratio);
    if (tools->current_tool == tools->eraser)
        eraser_cursor(x_ratio, y_ratio);
    if (tools->current_tool == tools->bucket)
        bucket_cursor(x_ratio, y_ratio);
}
