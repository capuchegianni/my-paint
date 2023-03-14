/*
** EPITECH PROJECT, 2023
** my-paint_gianni
** File description:
** help_text
*/

#include "../../../include/header.h"

void add_heart(void)
{
    sfTexture *love = sfTexture_createFromFile("assets/images/heart.png",NULL);
    sfSprite *heart_sprite = sfSprite_create();
    sfVector2f heart_pos = {1100, 65};

    sfSprite_setScale(heart_sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setTexture(heart_sprite, love, sfTrue);
    sfSprite_setPosition(heart_sprite, heart_pos);
    sfRenderWindow_drawSprite(window, heart_sprite, NULL);
}

void base_prints(void)
{
    char *welcome = "Thank you for using our paint program!";
    char *big_str = "To be able to draw, you need to click on the left button \
of your mouse while being above the canvas.\nYou can select either a pencil \
or an eraser in the edition menu.\nTo change the color of your pencil, you \
have to click on a colored square in the left menu.\nYou can also change the \
size of your pencil by clicking on the size button in the left menu.\n";

    my_print_text(window, 50, (sfVector2f){10, 60}, welcome);
    my_print_text(window, 20, (sfVector2f){10, 130}, big_str);
    add_heart();
}
