/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_move_sprite
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_csfml.h"

int my_animated_sprite(sfRenderWindow *window, int i)
{
    sfIntRect rect = {0, 0, 47, 53};
    sfTexture *texture = sfTexture_createFromFile(\
        "assets/images/luffyrun.png", &rect);
    sfSprite *luffy = sfSprite_create();
    sfVector2f move = {i, rand() % 100};

    sfSprite_setTexture(luffy, texture, sfTrue);
    sfSprite_setTextureRect(luffy, rect);
    sfSprite_setScale(luffy, (sfVector2f){2.5, 2.5});
    sfSprite_move(luffy, move);
    my_click_sprite(window, luffy, i);
    sfRenderWindow_drawSprite(window, luffy, NULL);
    if (move.x >= 1920) {
        sfRenderWindow_close(window);
    }
}
