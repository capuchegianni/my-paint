/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** display_submenu
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

void display_pencil_shape(tool_bar_t *bar)
{
    sfRenderWindow_drawText(window, bar->pencil_shape->text, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->pencil_shape->square->out, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->pencil_shape->square->form, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->pencil_shape->circle->out, NULL);
    sfRenderWindow_drawCircleShape(window,
    bar->pencil_shape->circle->form, NULL);
}

void display_eraser_shape(tool_bar_t *bar)
{
    sfRenderWindow_drawText(window, bar->eraser_shape->text, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->eraser_shape->square->out, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->eraser_shape->square->form, NULL);
    sfRenderWindow_drawRectangleShape(window,
    bar->eraser_shape->circle->out, NULL);
    sfRenderWindow_drawCircleShape(window,
    bar->eraser_shape->circle->form, NULL);
}

void display_toolbar(tool_bar_t *bar)
{
    hover_pencilless(bar);
    hover_pencilmore(bar);
    hover_eraserless(bar);
    hover_erasermore(bar);
    hover_pencilsquare(bar);
    hover_pencilcircle(bar);
    hover_erasersquare(bar);
    hover_erasercircle(bar);

    sfRenderWindow_drawRectangleShape(window, bar->rect, NULL);

    display_pencil_size(bar);
    display_eraser_size(bar);
    display_pencil_shape(bar);
    display_eraser_shape(bar);
}
