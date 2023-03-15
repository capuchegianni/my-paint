/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** bar
*/

#include "../../include/header.h"

void display_pencil_size(tool_bar_t *bar)
{
    sfRenderWindow_drawText(window, bar->pencil_size->text, NULL);
    sfRenderWindow_drawText(window, bar->pencil_size->tnbr, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->pencil_size->less->rect, NULL);
    sfRenderWindow_drawText(window, bar->pencil_size->less->text, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->pencil_size->more->rect, NULL);
    sfRenderWindow_drawText(window, bar->pencil_size->more->text, NULL);
}

void display_eraser_size(tool_bar_t *bar)
{
    sfRenderWindow_drawText(window, bar->eraser_size->text, NULL);
    sfRenderWindow_drawText(window, bar->eraser_size->tnbr, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->eraser_size->less->rect, NULL);
    sfRenderWindow_drawText(window, bar->eraser_size->less->text, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->eraser_size->more->rect, NULL);
    sfRenderWindow_drawText(window, bar->eraser_size->more->text, NULL);
}

void display_toolbar(tool_bar_t *bar)
{
    hover_pencilless(bar);
    hover_pencilmore(bar);
    hover_eraserless(bar);
    hover_erasermore(bar);

    sfRenderWindow_drawRectangleShape(window, bar->rect, NULL);

    display_pencil_size(bar);
    display_eraser_size(bar);
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
    sfRectangleShape_setFillColor(bar->rect, sfColor_fromRGB(194, 194, 194));
    sfRectangleShape_setOutlineThickness(bar->rect, 2);
    sfRectangleShape_setOutlineColor(bar->rect, sfBlack);

    bar = pencil_size(bar);
    bar = eraser_size(bar);

    return (bar);
}