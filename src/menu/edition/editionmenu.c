/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** editionmenu
*/

#include "../../../include/header.h"

void display_editionbuttons(buttonmenu_t *pencilbutton,
buttonmenu_t *eraserbutton)
{
    hover_eraserbutton(eraserbutton);
    sfRenderWindow_drawRectangleShape(window, eraserbutton->rect, NULL);
    sfRenderWindow_drawText(window, eraserbutton->text, NULL);
    hover_pencilbutton(pencilbutton);
    sfRenderWindow_drawRectangleShape(window, pencilbutton->rect, NULL);
    sfRenderWindow_drawText(window, pencilbutton->text, NULL);
}

void click_editionmenu(editionmenu_t *menu, buttonmenu_t *pencilbutton,
buttonmenu_t *eraserbutton)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
    sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);

    if (mouse_pos.x >= menu_pos.x && mouse_pos.x <= menu_pos.x + menu_size.x &&
        mouse_pos.y >= menu_pos.y && mouse_pos.y <= menu_pos.y + menu_size.y) {
        menu->hover = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            menu->pressed = 1;
            menu->clicked = 1;
            sfRectangleShape_setFillColor(menu->rect,
            sfColor_fromRGB(169, 169, 169));
        }
        menu->pressed = 0;
    } else {
        menu->hover = 0;
    }
    if (menu->clicked == 1)
        display_editionbuttons(pencilbutton, eraserbutton);
}

void hover_editionmenu(editionmenu_t *menu, buttonmenu_t *pencilbutton,
buttonmenu_t *eraserbutton)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
    sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);

    click_editionmenu(menu, pencilbutton, eraserbutton);
    if (mouse_pos.x < menu_pos.x || mouse_pos.x > menu_pos.x + menu_size.x ||
    mouse_pos.y < menu_pos.y ||
    mouse_pos.y > menu_pos.y + (menu_size.y * 3)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(menu->rect, menu->color);
            menu->clicked = 0;
        }
    }
}

editionmenu_t *set_editionmenu(editionmenu_t *menu)
{
    sfRectangleShape_setPosition(menu->rect, menu->position);
    sfRectangleShape_setSize(menu->rect, menu->size);
    sfRectangleShape_setFillColor(menu->rect, menu->color);
    sfRectangleShape_setOutlineThickness(menu->rect, 1);
    sfRectangleShape_setOutlineColor(menu->rect, sfBlack);

    sfText_setString(menu->text, "EDITION");
    sfText_setColor(menu->text, menu->text_color);
    sfText_setFont(menu->text, menu->font);
    sfText_setCharacterSize(menu->text, menu->text_size);
    sfText_setPosition(menu->text, menu->text_pos);

    return (menu);
}

editionmenu_t *init_editionmenu(void)
{
    editionmenu_t *menu = malloc(sizeof(editionmenu_t));

    menu->rect = sfRectangleShape_create();
    menu->position = (sfVector2f){200, 0};
    menu->size = (sfVector2f){200, 50};
    menu->color = sfColor_fromRGB(105, 105, 105);
    menu->clicked = 0;
    menu->hover = 0;
    menu->text = sfText_create();
    menu->font = sfFont_createFromFile("assets/fonts/font.otf");
    menu->text_pos = (sfVector2f){menu->position.x + 50, menu->position.y + 6};
    menu->text_color = sfBlack;
    menu->text_size = 30;

    menu = set_editionmenu(menu);

    return (menu);
}
