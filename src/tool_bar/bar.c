/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** bar
*/

#include "../../include/header.h"

void display_color_text(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");

    sfText_setString(text, "Pencil colors");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){45, 700});
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

tool_bar_t *tool_bar(void)
{
    tool_bar_t *bar = malloc(sizeof(tool_bar_t));
    bar->rect = sfRectangleShape_create();
    bar->pos = (sfVector2f){0, 200};
    bar->size = (sfVector2f){250, 810};
    bar->color = sfWhite;
    sfRectangleShape_setPosition(bar->rect, bar->pos);
    sfRectangleShape_setSize(bar->rect, bar->size);
    sfRectangleShape_setFillColor(bar->rect, sfColor_fromRGB(215, 215, 215));
    sfRectangleShape_setOutlineThickness(bar->rect, 2);
    sfRectangleShape_setOutlineColor(bar->rect, sfBlack);

    bar = pencil_size(bar);
    bar = eraser_size(bar);
    bar = pencil_shape(bar);
    bar = eraser_shape(bar);

    return (bar);
}
