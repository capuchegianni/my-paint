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
    sfTexture *texture =
    sfTexture_createFromFile("assets/images/pencil.png", NULL);
    sfVector2f scale = {0.03, 0.03};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void eraser_cursor(double x_ratio, double y_ratio)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/images/eraser.png", NULL);
    sfVector2u sprite_size = sfTexture_getSize(texture);
    sfVector2f scale = {0.05, 0.05};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setRotation(sprite, 90);
    sfSprite_setOrigin(sprite, (sfVector2f){sprite_size.x / 4,
    sprite_size.y - (sprite_size.y / 4)});
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void bucket_cursor(double x_ratio, double y_ratio)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/images/bucket.png", NULL);
    sfVector2f scale = {0.05, 0.05};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, (sfVector2f){(mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
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
