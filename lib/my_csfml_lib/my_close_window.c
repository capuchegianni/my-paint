/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** close_window
*/

#include <SFML/Graphics.h>
#include "my_csfml_lib.h"

int my_close_window(sfRenderWindow *window)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)
    && event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(window);
        return 1;
    }
    return 0;
}
