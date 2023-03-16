/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** close_window
*/

#include <SFML/Graphics.h>
#include "my_csfml.h"

int my_close_window(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 1;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            sfRenderWindow_close(window);
            return 1;
        }
    }
    return 0;
}
