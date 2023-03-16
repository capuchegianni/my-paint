/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** pencil_shape
*/

#include "../../../include/header.h"

void pencil_shapetext(tool_bar_t *bar)
{
    bar->pencil_shape->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->pencil_shape->text, font);
    sfText_setString(bar->pencil_shape->text, "Pencil shape");
    sfText_setCharacterSize(bar->pencil_shape->text, 30);
    sfText_setPosition(bar->pencil_shape->text, (sfVector2f){45, 445});
    sfText_setColor(bar->pencil_shape->text, sfBlack);
}

void pencil_square(tool_bar_t *bar)
{
    sfRectangleShape_setOrigin(bar->pencil_shape->square->out,
    (sfVector2f){20, 20});
    sfRectangleShape_setSize(bar->pencil_shape->square->out,
    bar->pencil_shape->square->size);
    sfRectangleShape_setPosition(bar->pencil_shape->square->out,
    bar->pencil_shape->square->pos);
    sfRectangleShape_setOutlineColor(bar->pencil_shape->square->out, sfBlack);
    sfRectangleShape_setOutlineThickness(bar->pencil_shape->square->out, 2);
    sfRectangleShape_setFillColor(bar->pencil_shape->square->out,
    bar->pencil_shape->square->color);
    bar->pencil_shape->square->form = sfRectangleShape_create();
    sfRectangleShape_setOrigin(bar->pencil_shape->square->form,
    (sfVector2f){15, 15});
    sfRectangleShape_setSize(bar->pencil_shape->square->form,
    (sfVector2f){30, 30});
    sfRectangleShape_setPosition(bar->pencil_shape->square->form,
    (sfVector2f){75, 520});
    sfRectangleShape_setFillColor(bar->pencil_shape->square->form, sfBlack);
}

void pencil_circle(tool_bar_t *bar)
{
    sfRectangleShape_setOrigin(bar->pencil_shape->circle->out,
    (sfVector2f){20, 20});
    sfRectangleShape_setSize(bar->pencil_shape->circle->out,
    bar->pencil_shape->circle->size);
    sfRectangleShape_setPosition(bar->pencil_shape->circle->out,
    bar->pencil_shape->circle->pos);
    sfRectangleShape_setOutlineColor(bar->pencil_shape->circle->out, sfBlack);
    sfRectangleShape_setOutlineThickness(bar->pencil_shape->circle->out, 2);
    sfRectangleShape_setFillColor(bar->pencil_shape->circle->out,
    bar->pencil_shape->circle->color);
    bar->pencil_shape->circle->form = sfCircleShape_create();
    sfCircleShape_setOrigin(bar->pencil_shape->circle->form,
    (sfVector2f){15, 15});
    sfCircleShape_setRadius(bar->pencil_shape->circle->form, 15);
    sfCircleShape_setPosition(bar->pencil_shape->circle->form,
    (sfVector2f){175, 520});
    sfCircleShape_setFillColor(bar->pencil_shape->circle->form,
    sfBlack);
}

void init_pencil_vals(tool_bar_t *bar)
{
    bar->pencil_shape->square->out = sfRectangleShape_create();
    bar->pencil_shape->square->pos = (sfVector2f){75, 520};
    bar->pencil_shape->square->size = (sfVector2f){40, 40};
    bar->pencil_shape->square->color = sfColor_fromRGB(194, 194, 194);
    bar->pencil_shape->square->clicked = 0;

    bar->pencil_shape->circle->out = sfRectangleShape_create();
    bar->pencil_shape->circle->pos = (sfVector2f){175, 520};
    bar->pencil_shape->circle->size = (sfVector2f){40, 40};
    bar->pencil_shape->circle->color = sfColor_fromRGB(194, 194, 194);
    bar->pencil_shape->circle->clicked = 0;
}

tool_bar_t *pencil_shape(tool_bar_t *bar)
{
    bar->pencil_shape = malloc(sizeof(pencil_shape_t));
    pencil_shapetext(bar);

    bar->pencil_shape->square = malloc(sizeof(square_t));
    bar->pencil_shape->circle = malloc(sizeof(circle_t));

    init_pencil_vals(bar);

    pencil_square(bar);
    pencil_circle(bar);

    return (bar);
}
