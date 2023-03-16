/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** eraser_shape
*/

#include "../../../include/header.h"

void eraser_shapetext(tool_bar_t *bar)
{
    bar->eraser_shape->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->eraser_shape->text, font);
    sfText_setString(bar->eraser_shape->text, "Eraser shape");
    sfText_setCharacterSize(bar->eraser_shape->text, 30);
    sfText_setPosition(bar->eraser_shape->text, (sfVector2f){40, 565});
    sfText_setColor(bar->eraser_shape->text, sfBlack);
}

void eraser_square(tool_bar_t *bar)
{
    sfRectangleShape_setOrigin(bar->eraser_shape->square->out,
    (sfVector2f){20, 20});
    sfRectangleShape_setSize(bar->eraser_shape->square->out,
    bar->eraser_shape->square->size);
    sfRectangleShape_setPosition(bar->eraser_shape->square->out,
    bar->eraser_shape->square->pos);
    sfRectangleShape_setOutlineColor(bar->eraser_shape->square->out, sfBlack);
    sfRectangleShape_setOutlineThickness(bar->eraser_shape->square->out, 2);
    sfRectangleShape_setFillColor(bar->eraser_shape->square->out,
    bar->eraser_shape->square->color);
    bar->eraser_shape->square->form = sfRectangleShape_create();
    sfRectangleShape_setOrigin(bar->eraser_shape->square->form,
    (sfVector2f){15, 15});
    sfRectangleShape_setSize(bar->eraser_shape->square->form,
    (sfVector2f){30, 30});
    sfRectangleShape_setPosition(bar->eraser_shape->square->form,
    (sfVector2f){75, 640});
    sfRectangleShape_setFillColor(bar->eraser_shape->square->form, sfBlack);
}

void eraser_circle(tool_bar_t *bar)
{
    sfRectangleShape_setOrigin(bar->eraser_shape->circle->out,
    (sfVector2f){20, 20});
    sfRectangleShape_setSize(bar->eraser_shape->circle->out,
    bar->eraser_shape->circle->size);
    sfRectangleShape_setPosition(bar->eraser_shape->circle->out,
    bar->eraser_shape->circle->pos);
    sfRectangleShape_setOutlineColor(bar->eraser_shape->circle->out, sfBlack);
    sfRectangleShape_setOutlineThickness(bar->eraser_shape->circle->out, 2);
    sfRectangleShape_setFillColor(bar->eraser_shape->circle->out,
    bar->eraser_shape->circle->color);
    bar->eraser_shape->circle->form = sfCircleShape_create();
    sfCircleShape_setOrigin(bar->eraser_shape->circle->form,
    (sfVector2f){15, 15});
    sfCircleShape_setRadius(bar->eraser_shape->circle->form, 15);
    sfCircleShape_setPosition(bar->eraser_shape->circle->form,
    (sfVector2f){175, 640});
    sfCircleShape_setFillColor(bar->eraser_shape->circle->form,
    sfBlack);
}

void init_eraser_vals(tool_bar_t *bar)
{
    bar->eraser_shape->square->out = sfRectangleShape_create();
    bar->eraser_shape->square->pos = (sfVector2f){75, 640};
    bar->eraser_shape->square->size = (sfVector2f){40, 40};
    bar->eraser_shape->square->color = sfColor_fromRGB(194, 194, 194);
    bar->eraser_shape->square->clicked = 0;

    bar->eraser_shape->circle->out = sfRectangleShape_create();
    bar->eraser_shape->circle->pos = (sfVector2f){175, 640};
    bar->eraser_shape->circle->size = (sfVector2f){40, 40};
    bar->eraser_shape->circle->color = sfColor_fromRGB(194, 194, 194);
    bar->eraser_shape->circle->clicked = 0;
}

tool_bar_t *eraser_shape(tool_bar_t *bar)
{
    bar->eraser_shape = malloc(sizeof(eraser_shape_t));
    eraser_shapetext(bar);

    bar->eraser_shape->square = malloc(sizeof(square_t));
    bar->eraser_shape->circle = malloc(sizeof(circle_t));

    init_eraser_vals(bar);

    eraser_square(bar);
    eraser_circle(bar);

    return (bar);
}
