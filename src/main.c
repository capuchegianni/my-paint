/*
** EPITECH PROJECT, 2023
** PROJECT_BUILDER
** File description:
** main
*/

#include "../include/header.h"

sfRenderWindow *window;
draw_area_t *area;
manage_tools_t *tools;

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

void init_tools(void)
{
    tools = malloc(sizeof(manage_tools_t));

    tools->pencil = malloc(sizeof(tool_t));
    tools->pencil->size = 5;
    tools->pencil->color = sfBlack;
    tools->pencil->shape = 0;

    tools->eraser = malloc(sizeof(tool_t));
    tools->eraser->size = 5;
    tools->eraser->color = sfWhite;
    tools->eraser->shape = 0;

    tools->current_tool = malloc(sizeof(tool_t));
    tools->current_tool = tools->pencil;
}

void init(char **av, global_filemenu_t **global_filemenu,
global_editionmenu_t **global_editionmenu, global_helpmenu_t **global_helpmenu)
{
    window = sfRenderWindow_create((sfVideoMode)
    {1920, 1080, 32}, "my_paint", sfClose | sfResize, NULL);

    init_area(av);
    init_tools();
    init_menu(global_filemenu, global_editionmenu, global_helpmenu);
}

int start_window(char **av)
{
    global_filemenu_t *global_filemenu = malloc(sizeof(global_filemenu_t));
    global_editionmenu_t *global_editionmenu =
    malloc(sizeof(global_editionmenu_t));
    global_helpmenu_t *global_helpmenu = malloc(sizeof(global_helpmenu_t));
    init(av, &global_filemenu, &global_editionmenu, &global_helpmenu);
    tool_bar_t *tbar = tool_bar();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfColor_fromRGB(245, 245, 245));
        display_bar();
        display_menu(window, global_filemenu, global_editionmenu,
        global_helpmenu);
        outline_area();
        sfRenderWindow_drawSprite(window, area->sprite, NULL);
        draw();
        display_toolbar(tbar);
        sfRenderWindow_display(window);
        my_close_window(window);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 1 && !av[0])
        return (84);

    if (av[1] && open(av[1], O_RDONLY) == -1) {
        my_printerr("Error: File not found.\n");
        return (84);
    }

    return (start_window(av));
}
