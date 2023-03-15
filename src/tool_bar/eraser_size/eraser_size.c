/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** eraser_size
*/

#include "../../../include/header.h"

void eraser_text(tool_bar_t *bar)
{
    bar->eraser_size->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->eraser_size->text, font);
    sfText_setString(bar->eraser_size->text, "Eraser size");
    sfText_setCharacterSize(bar->eraser_size->text, 30);
    sfText_setPosition(bar->eraser_size->text, (sfVector2f){55, 350});
    sfText_setColor(bar->eraser_size->text, sfBlack);
}

void eraser_nbr(tool_bar_t *bar)
{
    bar->eraser_size->nbr = tools->pencil->size;
    bar->eraser_size->tnbr = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->eraser_size->tnbr, font);
    char *strnbr = my_tostr(bar->eraser_size->nbr);
    sfText_setString(bar->eraser_size->tnbr, strnbr);
    sfText_setCharacterSize(bar->eraser_size->tnbr, 30);
    sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){120, 405});
    if (bar->eraser_size->nbr > 9)
        sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){115, 405});
    if (bar->eraser_size->nbr > 99)
        sfText_setPosition(bar->eraser_size->tnbr, (sfVector2f){110, 405});
    sfText_setColor(bar->eraser_size->tnbr, sfBlack);
}

void eraser_less(tool_bar_t *bar)
{
    bar->eraser_size->less->rect = sfRectangleShape_create();
    bar->eraser_size->less->size = (sfVector2f){20, 20};
    bar->eraser_size->less->pos = (sfVector2f){62, 415};
    bar->eraser_size->less->color = sfColor_fromRGB(194, 194, 194);
    bar->eraser_size->less->text = sfText_create();

    sfRectangleShape_setSize(bar->eraser_size->less->rect,
    bar->eraser_size->less->size);
    sfRectangleShape_setPosition(bar->eraser_size->less->rect,
    bar->eraser_size->less->pos);
    sfRectangleShape_setFillColor(bar->eraser_size->less->rect,
    bar->eraser_size->less->color);
    sfRectangleShape_setOutlineThickness(bar->eraser_size->less->rect, 2);
    sfRectangleShape_setOutlineColor(bar->eraser_size->less->rect, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->eraser_size->less->text, font);
    sfText_setString(bar->eraser_size->less->text, "-");
    sfText_setCharacterSize(bar->eraser_size->less->text, 30);
    sfText_setPosition(bar->eraser_size->less->text, (sfVector2f){65, 407});
    sfText_setColor(bar->eraser_size->less->text, sfBlack);
}

void eraser_more(tool_bar_t *bar)
{
    bar->eraser_size->more->rect = sfRectangleShape_create();
    bar->eraser_size->more->size = (sfVector2f){20, 20};
    bar->eraser_size->more->pos = (sfVector2f){170, 415};
    bar->eraser_size->more->color = sfColor_fromRGB(194, 194, 194);
    bar->eraser_size->more->text = sfText_create();

    sfRectangleShape_setSize(bar->eraser_size->more->rect,
    bar->eraser_size->more->size);
    sfRectangleShape_setPosition(bar->eraser_size->more->rect,
    bar->eraser_size->more->pos);
    sfRectangleShape_setFillColor(bar->eraser_size->more->rect,
    bar->eraser_size->more->color);
    sfRectangleShape_setOutlineThickness(bar->eraser_size->more->rect, 2);
    sfRectangleShape_setOutlineColor(bar->eraser_size->more->rect, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->eraser_size->more->text, font);
    sfText_setString(bar->eraser_size->more->text, "+");
    sfText_setCharacterSize(bar->eraser_size->more->text, 30);
    sfText_setPosition(bar->eraser_size->more->text, (sfVector2f){173, 407});
    sfText_setColor(bar->eraser_size->more->text, sfBlack);
}

tool_bar_t *eraser_size(tool_bar_t *bar)
{
    bar->eraser_size = malloc(sizeof(eraser_size_t));
    eraser_text(bar);
    eraser_nbr(bar);

    bar->eraser_size->less = malloc(sizeof(less_t));
    bar->eraser_size->more = malloc(sizeof(more_t));
    eraser_less(bar);
    eraser_more(bar);

    return (bar);
}
