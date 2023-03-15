/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** draw_area
*/

#include "../../include/header.h"

void outline_area(void)
{
    sfRectangleShape *img_outline = sfRectangleShape_create();
    sfVector2f img_outline_size = {1440, 810};
    sfVector2f img_outline_pos = {400, 200};

    sfRectangleShape_setSize(img_outline, img_outline_size);
    sfRectangleShape_setPosition(img_outline, img_outline_pos);
    sfRectangleShape_setOutlineThickness(img_outline, 2);
    sfRectangleShape_setOutlineColor(img_outline, sfBlack);
    sfRenderWindow_drawRectangleShape(window, img_outline, NULL);
    sfRectangleShape_destroy(img_outline);
}

void set_area(int i)
{
    if (i == 1)
        area->image = sfImage_createFromColor(1920, 1080, sfWhite);
    area->img_size = sfImage_getSize(area->image);
    area->texture = sfTexture_create(area->img_size.x, area->img_size.y);
    area->sprite = sfSprite_create();
    area->pos = (sfVector2f){400, 200};
    sfVector2f size = (sfVector2f){area->img_size.x, area->img_size.y};
    area->scale = (sfVector2f){1440 / size.x, 810 / size.y};
    sfSprite_setPosition(area->sprite, area->pos);
    sfTexture_updateFromImage(area->texture, area->image, 0, 0);
    sfSprite_setTexture(area->sprite, area->texture, sfTrue);
    sfSprite_setScale(area->sprite, area->scale);
}

int check_extension(char **av)
{
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".jpg", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".png", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".bmp", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".gif", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".tga", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".pic", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".psd", 4) == 0)
        return 1;
    if (my_strncmp(av[1] + my_strlen(av[1]) - 4, ".hdr", 4) == 0)
        return 1;
    return 0;
}

void init_area(char **av)
{
    area = malloc(sizeof(draw_area_t));
    if (av[1] != NULL && check_extension(av) == 1) {
        area->image = sfImage_createFromFile(av[1]);
        area->save_path = av[1];
    } else {
        area->image = sfImage_createFromColor(1920, 1080, sfWhite);
        area->save_path = "image.jpg";
    }
    set_area(0);
}
