/*
** EPITECH PROJECT, 2023
** PROJECT_BUILDER
** File description:
** main
*/

#include "../include/header.h"

sfRenderWindow *window;

int event_actions(void)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
    }
    return (0);
}

void init_window(void)
{
    window = sfRenderWindow_create((sfVideoMode)
    {1920, 1080, 32}, "my_paint", sfClose | sfResize, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
}

void init_menu(global_filemenu_t **global_filemenu,
global_editionmenu_t **global_editionmenu, global_helpmenu_t **global_helpmenu)
{
    global_filemenu_t *global_filemenu_cp = malloc(sizeof(global_filemenu_t));
    global_filemenu_cp->filemenu = init_filemenu();
    global_filemenu_cp->newfile = init_newfilebutton();
    global_filemenu_cp->openfile = init_openfilebutton();
    global_filemenu_cp->savefile = init_savefilebutton();
    *global_filemenu = global_filemenu_cp;

    global_editionmenu_t *global_editionmenu_cp =
    malloc(sizeof(global_editionmenu_t));
    global_editionmenu_cp->editionmenu = init_editionmenu();
    global_editionmenu_cp->eraser = init_eraserbutton();
    global_editionmenu_cp->pencil = init_pencilbutton();
    *global_editionmenu = global_editionmenu_cp;

    global_helpmenu_t *global_helpmenu_cp = malloc(sizeof(global_helpmenu_t));
    global_helpmenu_cp->helpmenu = init_helpmenu();
    global_helpmenu_cp->about = init_aboutbutton();
    global_helpmenu_cp->help = init_helpbutton();
    *global_helpmenu = global_helpmenu_cp;
}

void start_window(void)
{
    global_filemenu_t *global_filemenu = malloc(sizeof(global_filemenu_t));
    global_editionmenu_t *global_editionmenu =
    malloc(sizeof(global_editionmenu_t));
    global_helpmenu_t *global_helpmenu = malloc(sizeof(global_helpmenu_t));
    init_window();
    init_menu(&global_filemenu, &global_editionmenu, &global_helpmenu);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        hover_filemenu(global_filemenu->filemenu, global_filemenu->newfile,
        global_filemenu->openfile, global_filemenu->savefile);
        hover_editionmenu(global_editionmenu->editionmenu,
        global_editionmenu->pencil, global_editionmenu->eraser);
        hover_helpmenu(global_helpmenu->helpmenu,
        global_helpmenu->about, global_helpmenu->help);
        display_menu(window, global_filemenu->filemenu,
        global_editionmenu->editionmenu, global_helpmenu->helpmenu);
        sfRenderWindow_display(window);
        event_actions();
    }
}

int main(int ac, char **av)
{
    if (ac != 1 && !av[0])
        return (84);

    start_window();
}
