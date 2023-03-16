/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** pencil_size
*/

#include "../../../include/header.h"

void pencil_text(tool_bar_t *bar)
{
    bar->pencil_size->text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->pencil_size->text, font);
    sfText_setString(bar->pencil_size->text, "Pencil size");
    sfText_setCharacterSize(bar->pencil_size->text, 30);
    sfText_setPosition(bar->pencil_size->text, (sfVector2f){60, 225});
    sfText_setColor(bar->pencil_size->text, sfBlack);
}

void pencil_nbr(tool_bar_t *bar)
{
    bar->pencil_size->nbr = tools->pencil->size;
    bar->pencil_size->tnbr = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->pencil_size->tnbr, font);
    char *strnbr = my_tostr(bar->pencil_size->nbr);
    sfText_setString(bar->pencil_size->tnbr, strnbr);
    sfText_setCharacterSize(bar->pencil_size->tnbr, 30);
    sfText_setPosition(bar->pencil_size->tnbr, (sfVector2f){120, 270});
    if (bar->pencil_size->nbr > 9)
        sfText_setPosition(bar->pencil_size->tnbr, (sfVector2f){115, 270});
    if (bar->pencil_size->nbr > 99)
        sfText_setPosition(bar->pencil_size->tnbr, (sfVector2f){110, 270});
    sfText_setColor(bar->pencil_size->tnbr, sfBlack);
}

void pencil_less(tool_bar_t *bar)
{
    bar->pencil_size->less->rect = sfRectangleShape_create();
    bar->pencil_size->less->size = (sfVector2f){20, 20};
    bar->pencil_size->less->pos = (sfVector2f){62, 280};
    bar->pencil_size->less->color = sfColor_fromRGB(194, 194, 194);
    bar->pencil_size->less->text = sfText_create();

    sfRectangleShape_setSize(bar->pencil_size->less->rect,
    bar->pencil_size->less->size);
    sfRectangleShape_setPosition(bar->pencil_size->less->rect,
    bar->pencil_size->less->pos);
    sfRectangleShape_setFillColor(bar->pencil_size->less->rect,
    bar->pencil_size->less->color);
    sfRectangleShape_setOutlineThickness(bar->pencil_size->less->rect, 2);
    sfRectangleShape_setOutlineColor(bar->pencil_size->less->rect, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->pencil_size->less->text, font);
    sfText_setString(bar->pencil_size->less->text, "-");
    sfText_setCharacterSize(bar->pencil_size->less->text, 30);
    sfText_setPosition(bar->pencil_size->less->text, (sfVector2f){65, 272});
    sfText_setColor(bar->pencil_size->less->text, sfBlack);
}

void pencil_more(tool_bar_t *bar)
{
    bar->pencil_size->more->rect = sfRectangleShape_create();
    bar->pencil_size->more->size = (sfVector2f){20, 20};
    bar->pencil_size->more->pos = (sfVector2f){170, 280};
    bar->pencil_size->more->color = sfColor_fromRGB(194, 194, 194);
    bar->pencil_size->more->text = sfText_create();

    sfRectangleShape_setSize(bar->pencil_size->more->rect,
    bar->pencil_size->more->size);
    sfRectangleShape_setPosition(bar->pencil_size->more->rect,
    bar->pencil_size->more->pos);
    sfRectangleShape_setFillColor(bar->pencil_size->more->rect,
    bar->pencil_size->more->color);
    sfRectangleShape_setOutlineThickness(bar->pencil_size->more->rect, 2);
    sfRectangleShape_setOutlineColor(bar->pencil_size->more->rect, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/fonts/font.otf");
    sfText_setFont(bar->pencil_size->more->text, font);
    sfText_setString(bar->pencil_size->more->text, "+");
    sfText_setCharacterSize(bar->pencil_size->more->text, 30);
    sfText_setPosition(bar->pencil_size->more->text, (sfVector2f){173, 272});
    sfText_setColor(bar->pencil_size->more->text, sfBlack);
}

tool_bar_t *pencil_size(tool_bar_t *bar)
{
    bar->pencil_size = malloc(sizeof(pencil_size_t));
    pencil_text(bar);
    pencil_nbr(bar);

    bar->pencil_size->less = malloc(sizeof(less_t));
    bar->pencil_size->more = malloc(sizeof(more_t));
    pencil_less(bar);
    pencil_more(bar);

    return (bar);
}
