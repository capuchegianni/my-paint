/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** filemenu
*/

#include "../../../include/header.h"

void display_filebuttons(buttonmenu_t *newfile, buttonmenu_t *openfile,
buttonmenu_t *savefile)
{
    hover_newfilebutton(newfile);
    sfRenderWindow_drawRectangleShape(window, newfile->rect, NULL);
    sfRenderWindow_drawText(window, newfile->text, NULL);
    hover_openfilebutton(openfile);
    sfRenderWindow_drawRectangleShape(window, openfile->rect, NULL);
    sfRenderWindow_drawText(window, openfile->text, NULL);
    hover_savefilebutton(savefile);
    sfRenderWindow_drawRectangleShape(window, savefile->rect, NULL);
    sfRenderWindow_drawText(window, savefile->text, NULL);
}

void click_filemenu(filemenu_t *menu, buttonmenu_t *newfile,
buttonmenu_t *openfile, buttonmenu_t *savefile)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
    sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);

    if (mouse_pos.x >= menu_pos.x && mouse_pos.x <= menu_pos.x + menu_size.x &&
        mouse_pos.y >= menu_pos.y && mouse_pos.y <= menu_pos.y + menu_size.y) {
        menu->hover = 1;
        sfRectangleShape_setFillColor(menu->rect,sfColor_fromRGB(181,181,181));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            menu->pressed = 1;
            menu->clicked = 1;
            sfRectangleShape_setFillColor(menu->rect,
            sfColor_fromRGB(169, 169, 169));
        } menu->pressed = 0;
    } else {
        sfRectangleShape_setFillColor(menu->rect, menu->color);
        menu->hover = 0;
    }
    if (menu->clicked == 1)
        display_filebuttons(newfile, openfile, savefile);
}

void hover_filemenu(filemenu_t *menu, buttonmenu_t *newfile,
buttonmenu_t *openfile, buttonmenu_t *savefile)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f menu_pos = sfRectangleShape_getPosition(menu->rect);
    sfVector2f menu_size = sfRectangleShape_getSize(menu->rect);

    click_filemenu(menu, newfile, openfile, savefile);
    if (mouse_pos.x < menu_pos.x || mouse_pos.x > menu_pos.x + menu_size.x ||
    mouse_pos.y < menu_pos.y ||
    mouse_pos.y > menu_pos.y + (menu_size.y * 4)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setFillColor(menu->rect, menu->color);
            menu->clicked = 0;
        }
    }
}

filemenu_t *set_filemenu(filemenu_t *menu)
{
    sfRectangleShape_setPosition(menu->rect, menu->position);
    sfRectangleShape_setSize(menu->rect, menu->size);
    sfRectangleShape_setFillColor(menu->rect, menu->color);
    sfRectangleShape_setOutlineThickness(menu->rect, 1);
    sfRectangleShape_setOutlineColor(menu->rect, sfBlack);

    sfText_setString(menu->text, "FILE");
    sfText_setColor(menu->text, menu->text_color);
    sfText_setFont(menu->text, menu->font);
    sfText_setCharacterSize(menu->text, menu->text_size);
    sfText_setPosition(menu->text, menu->text_pos);

    return (menu);
}

filemenu_t *init_filemenu(void)
{
    filemenu_t *menu = malloc(sizeof(filemenu_t));

    menu->rect = sfRectangleShape_create();
    menu->position = (sfVector2f){0, 0};
    menu->size = (sfVector2f){200, 50};
    menu->color = sfColor_fromRGB(194, 194, 194);
    menu->clicked = 0;
    menu->hover = 0;
    menu->text = sfText_create();
    menu->font = sfFont_createFromFile("assets/fonts/font.otf");
    menu->text_pos = (sfVector2f){menu->position.x + 70, menu->position.y + 6};
    menu->text_color = sfBlack;
    menu->text_size = 30;

    menu = set_filemenu(menu);

    return (menu);
}
