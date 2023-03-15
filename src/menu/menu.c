/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** menu
*/

#include "../../include/header.h"

void display_menu(sfRenderWindow *window, global_filemenu_t *global_filemenu,
global_editionmenu_t *global_editionmenu, global_helpmenu_t *global_helpmenu)
{
    hover_filemenu(global_filemenu->filemenu, global_filemenu->newfile,
    global_filemenu->openfile, global_filemenu->savefile);
    hover_editionmenu(global_editionmenu->editionmenu,
    global_editionmenu->pencil, global_editionmenu->eraser);
    hover_helpmenu(global_helpmenu->helpmenu,
    global_helpmenu->about, global_helpmenu->help);

    sfRenderWindow_drawRectangleShape(window,
    global_filemenu->filemenu->rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
    global_editionmenu->editionmenu->rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
    global_helpmenu->helpmenu->rect, NULL);
    sfRenderWindow_drawText(window, global_filemenu->filemenu->text, NULL);
    sfRenderWindow_drawText(window,
    global_editionmenu->editionmenu->text, NULL);
    sfRenderWindow_drawText(window, global_helpmenu->helpmenu->text, NULL);
}

void display_bar(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f rect_size = {1920, 50};
    sfVector2f rect_pos = {0, 0};

    sfRectangleShape_setSize(rect, rect_size);
    sfRectangleShape_setPosition(rect, rect_pos);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(194, 194, 194));
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}
