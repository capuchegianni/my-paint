/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_cursor
*/

#include <SFML/Graphics.h>
#include "my_csfml_lib.h"
#include "../../include/my.h"

void my_cursor(sfRenderWindow *window)
{
    sfIntRect cursor = {0, 0, 640, 640};
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile(\
        "assets/images/cursor.png", &cursor);
    sfSprite *sprite = sfSprite_create();
    sfVector2f mouse = {0, 0};

    sfSprite_setTexture(sprite, texture, sfTrue);
    if (event.type == sfEvtMouseMoved) {
        mouse.x = event.mouseMove.x;
        mouse.y = event.mouseMove.y;
        sfSprite_setPosition(sprite, mouse);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}
