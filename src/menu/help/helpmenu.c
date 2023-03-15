/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** helpmenu
*/

#include "../../../include/header.h"

void display_helpbuttons(buttonmenu_t *about, buttonmenu_t *help,
helpmenu_t *menu)
{
    if (hover_aboutbutton(about) == 1) {
        sfRectangleShape_setFillColor(menu->rect, menu->color);
        menu->clicked = 0;
    }
    sfRenderWindow_drawRectangleShape(window, about->rect, NULL);
    sfRenderWindow_drawText(window, about->text, NULL);
    if (hover_helpbutton(help) == 1 ) {
        sfRectangleShape_setFillColor(menu->rect, menu->color);
        menu->clicked = 0;
    }
    sfRenderWindow_drawRectangleShape(window, help->rect, NULL);
    sfRenderWindow_drawText(window, help->text, NULL);
}

void click_helpmenu(helpmenu_t *menu, buttonmenu_t *about, buttonmenu_t *help)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfFloatRect menu_size = sfRectangleShape_getGlobalBounds(menu->rect);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;
    if (sfFloatRect_contains(&menu_size, (mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)) == sfTrue) {
        menu->hover = 1;
        sfRectangleShape_setFillColor(menu->rect,sfColor_fromRGB(181,181,181));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            menu->pressed = 1;
            menu->clicked = 1;
            sfRectangleShape_setFillColor(menu->rect,
            sfColor_fromRGB(169, 169, 169));
        } menu->pressed = 0;
    } else {
        menu->hover = 0;
        sfRectangleShape_setFillColor(menu->rect, menu->color);
    } if (menu->clicked == 1)
        display_helpbuttons(about, help, menu);
}

void hover_helpmenu(helpmenu_t *menu, buttonmenu_t *about, buttonmenu_t *help)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;

    click_helpmenu(menu, about, help);
    if ((mouse_pos.x / x_ratio) < menu_pos.x ||
    (mouse_pos.x / x_ratio) > menu_pos.x + menu_size.x ||
    (mouse_pos.y / y_ratio) < menu_pos.y ||
    (mouse_pos.y / y_ratio) > menu_pos.y + (menu_size.y * 3)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(menu->rect, menu->color);
            menu->clicked = 0;
        }
    }
}

helpmenu_t *set_helpmenu(helpmenu_t *menu)
{
    sfRectangleShape_setPosition(menu->rect, menu->position);
    sfRectangleShape_setSize(menu->rect, menu->size);
    sfRectangleShape_setFillColor(menu->rect, menu->color);
    sfRectangleShape_setOutlineThickness(menu->rect, 1);
    sfRectangleShape_setOutlineColor(menu->rect, sfBlack);

    sfText_setString(menu->text, "HELP");
    sfText_setColor(menu->text, menu->text_color);
    sfText_setFont(menu->text, menu->font);
    sfText_setCharacterSize(menu->text, menu->text_size);
    sfText_setPosition(menu->text, menu->text_pos);

    return (menu);
}

helpmenu_t *init_helpmenu(void)
{
    helpmenu_t *menu = malloc(sizeof(helpmenu_t));

    menu->rect = sfRectangleShape_create();
    menu->position = (sfVector2f){400, 0};
    menu->size = (sfVector2f){200, 50};
    menu->color = sfColor_fromRGB(194, 194, 194);
    menu->clicked = 0;
    menu->hover = 0;
    menu->text = sfText_create();
    menu->font = sfFont_createFromFile("assets/fonts/font.otf");
    menu->text_pos = (sfVector2f){menu->position.x + 75, menu->position.y + 6};
    menu->text_color = sfBlack;
    menu->text_size = 30;

    menu = set_helpmenu(menu);

    return (menu);
}
