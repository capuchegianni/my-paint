/*
** EPITECH PROJECT, 2023
** my-paint_gianni
** File description:
** rectangle_color
*/

#include "../../../include/header.h"

void change_color(sfRectangleShape *rect)
{
    sfFloatRect infos = sfRectangleShape_getGlobalBounds(rect);
    sfVector2i mous_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;

    if (sfFloatRect_contains(&infos, (mous_pos.x / x_ratio),
    (mous_pos.y / y_ratio)) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfColor color = sfRectangleShape_getFillColor(rect);
            tools->pencil->color = color;
        }
    }
}

void display_rectangle(sfVector2f pos, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {20, 20};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    change_color(rect);
    sfRectangleShape_destroy(rect);
}

void display_colors(void)
{
    display_rectangle((sfVector2f){45, 750}, sfWhite);
    display_rectangle((sfVector2f){113, 750}, sfColor_fromRGB(217, 217, 217));
    display_rectangle((sfVector2f){181, 750}, sfColor_fromRGB(143, 143, 143));
    display_rectangle((sfVector2f){181, 800}, sfColor_fromRGB(74, 74, 74));
    display_rectangle((sfVector2f){113, 800}, sfBlack);
    display_rectangle((sfVector2f){45, 800}, sfColor_fromRGB(3, 0, 201));
    display_rectangle((sfVector2f){45, 850}, sfColor_fromRGB(106, 0, 255));
    display_rectangle((sfVector2f){113, 850}, sfColor_fromRGB(221, 0, 255));
    display_rectangle((sfVector2f){181, 850}, sfColor_fromRGB(255, 0, 0));
    display_rectangle((sfVector2f){181, 900}, sfColor_fromRGB(140, 70, 20));
    display_rectangle((sfVector2f){113, 900}, sfColor_fromRGB(255, 123, 0));
    display_rectangle((sfVector2f){45, 900}, sfColor_fromRGB(255, 217, 0));
    display_rectangle((sfVector2f){45, 950}, sfColor_fromRGB(0, 255, 123));
    display_rectangle((sfVector2f){113, 950}, sfColor_fromRGB(0, 255, 229));
    display_rectangle((sfVector2f){181, 950}, sfColor_fromRGB(0, 157, 255));
}
