/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** help
*/

#include "../../../include/header.h"

void help_window(void)
{
    buttonmenu_t *back = init_back((sfVector2f){1720, 0},
    (sfVector2f){200, 50}, 6);

    while (1) {
        sfRectangleShape *rect = sfRectangleShape_create();
        sfVector2f rect_size = {1920, 1080};
        sfVector2f rect_pos = {0, 0};
        sfRectangleShape_setSize(rect, rect_size);
        sfRectangleShape_setPosition(rect, rect_pos);
        sfRectangleShape_setFillColor(rect, sfColor_fromRGB(240, 240, 240));
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        display_bar(); base_prints();
        sfRenderWindow_drawRectangleShape(window, back->rect, NULL);
        sfRenderWindow_drawText(window, back->text, NULL);
        sfRenderWindow_display(window);
        if (hover_back(back) == 1)
            return;
        if (my_close_window(window) == 1)
            return;
    }
}

int click_helpbutton(buttonmenu_t *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        button->pressed = 1;
        button->clicked = 1;
        sfRectangleShape_setFillColor(button->rect,
        sfColor_fromRGB(169, 169, 169));
        return (0);
    }
    if (button->clicked == 1) {
        help_window();
        button->pressed = 0;
        button->clicked = 0;
        return (1);
    }
    return (0);
}

int hover_helpbutton(buttonmenu_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);

    if (mouse_pos.x >= button_pos.x &&
    mouse_pos.x <= button_pos.x + button_size.x &&
    mouse_pos.y >= button_pos.y &&
    mouse_pos.y <= button_pos.y + button_size.y) {
        button->hover = 1;
        sfRectangleShape_setFillColor(button->rect,
        sfColor_fromRGB(181, 181, 181));
        return (click_helpbutton(button));
    } else {
        sfRectangleShape_setFillColor(button->rect, button->color);
        button->hover = 0;
        return (0);
    }
}

buttonmenu_t *set_helpbutton(buttonmenu_t *button)
{
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, button->color);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);

    sfText_setString(button->text, "Help");
    sfText_setColor(button->text, button->text_color);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, button->text_size);
    sfText_setPosition(button->text, button->text_pos);

    return (button);
}

buttonmenu_t *init_helpbutton(void)
{
    buttonmenu_t *button = malloc(sizeof(buttonmenu_t));

    button->rect = sfRectangleShape_create();
    button->position = (sfVector2f){400, 100};
    button->size = (sfVector2f){200, 50};
    button->color = sfColor_fromRGB(194, 194, 194);
    button->clicked = 0;
    button->hover = 0;
    button->text = sfText_create();
    button->font = sfFont_createFromFile("assets/fonts/font.otf");
    button->text_pos = (sfVector2f){button->position.x + 70,
    button->position.y + 6};
    button->text_color = sfBlack;
    button->text_size = 30;

    button = set_helpbutton(button);

    return (button);
}
