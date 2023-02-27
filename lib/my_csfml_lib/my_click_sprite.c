/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** click_sprite
*/

#include <SFML/Graphics.h>
#include "my_csfml_lib.h"
#include <stdio.h>

void loop(sfRenderWindow *window, sfSprite *sprite, int i)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(window);
            sfSprite_move(sprite, (sfVector2f){i, 0});
        }
    }
}

void my_click_sprite(sfRenderWindow *window, sfSprite *sprite, int i)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfVector2f sprite_size = sfSprite_getScale(sprite);
    sfFloatRect rect = {sprite_pos.x, sprite_pos.y,\
        (sprite_size.x * 47), (sprite_size.y) * 53};
    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y) == sfTrue) {
        loop(window, sprite, i);
    }
}
