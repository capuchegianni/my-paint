/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_window_is_too_small
*/

#include <SFML/Graphics.h>
#include "my_csfml_lib.h"
#include "../../include/my.h"

int my_window_too_small(sfRenderWindow *window, int width, int height)
{
    sfVector2u frame_size = sfRenderWindow_getSize(window);

    if (frame_size.x < width || frame_size.y < height) {
        return 1;
    }
    return 0;
}
