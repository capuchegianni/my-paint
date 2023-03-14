/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** draw_area
*/

#include "../../include/header.h"

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

int init_area(char **av)
{
    area = malloc(sizeof(draw_area_t));
    if (av[1] != NULL) {
        if (open(av[1], O_RDONLY) == -1) {
            my_printerr("Error: File not found.\n");
            return (84);
        }
        area->image = sfImage_createFromFile(av[1]);
        area->save_path = av[1];
    } else {
        area->image = sfImage_createFromColor(1920, 1080, sfWhite);
        area->save_path = "image.jpg";
    }
    set_area(0);
    return (0);
}
