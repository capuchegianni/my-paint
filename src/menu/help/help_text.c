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
    sfSprite_destroy(heart_sprite);
    sfTexture_destroy(love);
}

void add_important(void)
{
    sfTexture *important = sfTexture_createFromFile
    ("assets/images/bonus.png",NULL);
    sfSprite *important_sprite = sfSprite_create();
    sfVector2f important_pos = {120, 500};

    sfSprite_setScale(important_sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setTexture(important_sprite, important, sfTrue);
    sfSprite_setPosition(important_sprite, important_pos);
    sfRenderWindow_drawSprite(window, important_sprite, NULL);
    sfSprite_destroy(important_sprite);
    sfTexture_destroy(important);
}

void bonus_help(void)
{
    char *bucket = "- The bucket button is available in the edition menu. \
To fill the canvas with a color, you need to click on the left button of \
your mouse while being above the canvas.";
    char *colors = "- You can pick a color directly on the canvas by \
right clicking on the pixel where the color you want is.";

    my_print_text(window, 30, (sfVector2f){10, 510}, "Bonus:");
    add_important();
    my_print_text(window, 20, (sfVector2f){20, 550}, bucket);
    my_print_text(window, 20, (sfVector2f){20, 580}, colors);
}

void file_help(void)
{
    char *file = "- To create a new file, click on the newfile button \
in the file menu.";
    char *open = "- The button openfile in the file menu doesn't work yet. \
You can instead call a file in the terminal by typing: ./my_paint [file_name]";
    char *save = "- To save your file, click on the savefile button in the \
file menu.";

    my_print_text(window, 30, (sfVector2f){10, 360}, "File menu:");
    my_print_text(window, 20, (sfVector2f){20, 400}, file);
    my_print_text(window, 20, (sfVector2f){20, 430}, open);
    my_print_text(window, 20, (sfVector2f){20, 460}, save);
}

void base_prints(void)
{
    char *welcome = "Thank you for using our paint program!";
    char *draw = "- To draw, you need to click on the left button \
of your mouse while being above the canvas.";
    char *erase = "- The eraser button is available in the edition menu. \
To erase, you need to click on the left button of your mouse while being \
above the canvas.";
    char *colors = "- You can pick a color by left clicking on the color \
you want in the left menu.";
    char *size = "- Pencil/eraser size is available in the left menu.";
    char *shape = "- Pencil/eraser shape is available in the left menu.";
    my_print_text(window, 50, (sfVector2f){10, 60}, welcome);
    add_heart();
    my_print_text(window, 30, (sfVector2f){10, 150}, "Basis:");
    my_print_text(window, 20, (sfVector2f){20, 190}, draw);
    my_print_text(window, 20, (sfVector2f){20, 220}, erase);
    my_print_text(window, 20, (sfVector2f){20, 250}, colors);
    my_print_text(window, 20, (sfVector2f){20, 280}, size);
    my_print_text(window, 20, (sfVector2f){20, 310}, shape);
    file_help();
    bonus_help();
}
