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
