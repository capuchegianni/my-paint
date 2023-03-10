/*
** EPITECH PROJECT, 2023
** PROJECT_BUILDER
** File description:
** main
*/

#include "../include/header.h"

int event_actions(sfRenderWindow *window)
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

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode)
    {1920, 1080, 32}, "my_paint", sfClose | sfResize, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);

    return (window);
}

void start_window(void)
{
    sfRenderWindow *window = init_window();
    filemenu_t *filemenu = init_filemenu();
    editionmenu_t *editionmenu = init_editionmenu();
    helpmenu_t *helpmenu = init_helpmenu();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        hover_helpmenu(helpmenu, window);
        hover_editionmenu(editionmenu, window);
        hover_filemenu(filemenu, window);
        display_menu(window, filemenu, editionmenu, helpmenu);
        sfRenderWindow_display(window);
        event_actions(window);
    }
}

int main(int ac, char **av)
{
    if (ac != 1 && !av[0])
        return (84);

    start_window();
}
