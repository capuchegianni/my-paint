/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** eraser
*/

#include "../../../include/header.h"

void click_eraserbutton(buttonmenu_t *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        button->pressed = 1;
        button->clicked = 1;
        sfRectangleShape_setFillColor(button->rect,
        sfColor_fromRGB(169, 169, 169));
        return;
    }
    if (button->clicked == 1) {

    }
    sfRectangleShape_setFillColor(button->rect, button->color);
    button->pressed = 0;
    button->clicked = 0;
}

void hover_eraserbutton(buttonmenu_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);

    if (mouse_pos.x >= button_pos.x &&
    mouse_pos.x <= button_pos.x + button_size.x &&
    mouse_pos.y >= button_pos.y &&
    mouse_pos.y <= button_pos.y + button_size.y) {
        button->hover = 1;
        click_eraserbutton(button);
    } else {
        button->hover = 0;
    }
}

buttonmenu_t *set_eraserbutton(buttonmenu_t *button)
{
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, button->color);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);

    sfText_setString(button->text, "Eraser");
    sfText_setColor(button->text, button->text_color);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, button->text_size);
    sfText_setPosition(button->text, button->text_pos);

    return (button);
}

buttonmenu_t *init_eraserbutton(void)
{
    buttonmenu_t *button = malloc(sizeof(buttonmenu_t));

    button->rect = sfRectangleShape_create();
    button->position = (sfVector2f){200, 50};
    button->size = (sfVector2f){200, 50};
    button->color = sfColor_fromRGB(105, 105, 105);
    button->clicked = 0;
    button->hover = 0;
    button->text = sfText_create();
    button->font = sfFont_createFromFile("assets/fonts/font.otf");
    button->text_pos = (sfVector2f){button->position.x + 60,
    button->position.y + 6};
    button->text_color = sfBlack;
    button->text_size = 30;

    button = set_eraserbutton(button);

    return (button);
}
