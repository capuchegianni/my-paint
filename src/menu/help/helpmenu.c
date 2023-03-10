/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** helpmenu
*/

#include "../../../include/header.h"

void click_helpmenu(helpmenu_t *menu)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (menu->clicked == 0) {
            menu->color = sfColor_fromRGB(169, 169, 169);
            sfRectangleShape_setFillColor(menu->rect, menu->color);
            menu->clicked = 1;
        } else {
            menu->color = sfColor_fromRGB(105, 105, 105);
            sfRectangleShape_setFillColor(menu->rect, menu->color);
            menu->clicked = 0;
        }
        sfSleep((sfTime){150000});
    }
}

void hover_helpmenu(helpmenu_t *menu, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
    sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);

    if (mouse_pos.x >= menu_pos.x && mouse_pos.x <= menu_pos.x + menu_size.x &&
        mouse_pos.y >= menu_pos.y && mouse_pos.y <= menu_pos.y + menu_size.y) {
        menu->hover = 1;
        click_helpmenu(menu);
    } else {
        menu->hover = 0;
    }
}

helpmenu_t *set_helpmenu(helpmenu_t *menu)
{
    sfRectangleShape_setPosition(menu->rect, menu->position);
    sfRectangleShape_setSize(menu->rect, menu->size);
    sfRectangleShape_setFillColor(menu->rect, menu->color);
    sfRectangleShape_setOutlineThickness(menu->rect, 2);
    sfRectangleShape_setOutlineColor(menu->rect, sfBlack);

    sfText_setString(menu->text, "Help");
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
    menu->color = sfColor_fromRGB(105, 105, 105);
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
