/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_render_sprite
*/

#include <SFML/Graphics.h>
#include "my_csfml_lib.h"
#include "../../include/my.h"

int my_background(sfRenderWindow *window)
{
    sfTexture *background = sfTexture_createFromFile(\
        "assets/images/background.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;

    if (background == NULL || sprite == NULL)
        return 84;
    sfSprite_setTexture(sprite, background, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(background);
    sfSprite_destroy(sprite);
    return 0;
}
