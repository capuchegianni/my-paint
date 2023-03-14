/*
** EPITECH PROJECT, 2023
** my-paint_gianni
** File description:
** help_text
*/

#include "../../../include/header.h"

int click_back(buttonmenu_t *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        button->pressed = 1;
        button->clicked = 1;
        sfRectangleShape_setFillColor(button->rect,
        sfColor_fromRGB(169, 169, 169));
        return 0;
    }
    if (button->clicked == 1) {
        return 1;
    }
    button->pressed = 0;
    button->clicked = 0;
    return 0;
}

int hover_back(buttonmenu_t *back)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f back_pos = sfRectangleShape_getPosition(back->rect);
    sfVector2f back_size = sfRectangleShape_getSize(back->rect);

    if (mouse_pos.x >= back_pos.x && mouse_pos.x <= back_pos.x + back_size.x &&
        mouse_pos.y >= back_pos.y && mouse_pos.y <= back_pos.y + back_size.y) {
        back->hover = 1;
        sfRectangleShape_setFillColor(back->rect,
        sfColor_fromRGB(181, 181, 181));
        return click_back(back);
    } else {
        sfRectangleShape_setFillColor(back->rect, back->color);
        back->hover = 0;
    }
    return 0;
}

buttonmenu_t *set_back(buttonmenu_t *back)
{
    sfRectangleShape_setPosition(back->rect, back->position);
    sfRectangleShape_setSize(back->rect, back->size);
    sfRectangleShape_setFillColor(back->rect, back->color);
    sfRectangleShape_setOutlineThickness(back->rect, 1);
    sfRectangleShape_setOutlineColor(back->rect, sfBlack);

    sfText_setString(back->text, "Back");
    sfText_setColor(back->text, back->text_color);
    sfText_setFont(back->text, back->font);
    sfText_setCharacterSize(back->text, back->text_size);
    sfText_setPosition(back->text, back->text_pos);

    return back;
}

buttonmenu_t *init_back(sfVector2f pos, sfVector2f size, int height)
{
    buttonmenu_t *back = malloc(sizeof(buttonmenu_t));

    back->rect = sfRectangleShape_create();
    back->position = pos;
    back->size = size;
    back->color = sfColor_fromRGB(194, 194, 194);
    back->clicked = 0;
    back->hover = 0;
    back->text = sfText_create();
    back->font = sfFont_createFromFile("assets/fonts/font.otf");
    back->text_pos = (sfVector2f){back->position.x + 75,
    back->position.y + height};
    back->text_color = sfBlack;
    back->text_size = 30;

    back = set_back(back);

    return back;
}
