/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** bucket
*/

#include "../../../include/header.h"

int click_bucketbutton(buttonmenu_t *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        button->pressed = 1;
        button->clicked = 1;
        sfRectangleShape_setFillColor(button->rect,
        sfColor_fromRGB(169, 169, 169));
        return (0);
    }
    if (button->clicked == 1) {
        tools->current_tool = tools->bucket;
        button->pressed = 0;
        button->clicked = 0;
        return (1);
    }
    return (0);
}

int hover_bucketbutton(buttonmenu_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfFloatRect button_size = sfRectangleShape_getGlobalBounds(button->rect);
    double x_ratio = (double)window_size.x / 1920;
    double y_ratio = (double)window_size.y / 1016;

    if (sfFloatRect_contains(&button_size, (mouse_pos.x / x_ratio),
    (mouse_pos.y / y_ratio)) == sfTrue) {
        button->hover = 1;
        sfRectangleShape_setFillColor(button->rect,
        sfColor_fromRGB(181, 181, 181));
        return (click_bucketbutton(button));
    } else {
        sfRectangleShape_setFillColor(button->rect, button->color);
        button->hover = 0;
        return (0);
    }
}

buttonmenu_t *set_bucketbutton(buttonmenu_t *button)
{
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, button->color);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);

    sfText_setString(button->text, "bucket");
    sfText_setColor(button->text, button->text_color);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, button->text_size);
    sfText_setPosition(button->text, button->text_pos);

    return (button);
}

buttonmenu_t *init_bucketbutton(void)
{
    buttonmenu_t *button = malloc(sizeof(buttonmenu_t));

    button->rect = sfRectangleShape_create();
    button->position = (sfVector2f){200, 150};
    button->size = (sfVector2f){199, 48};
    button->color = sfColor_fromRGB(194, 194, 194);
    button->clicked = 0;
    button->hover = 0;
    button->text = sfText_create();
    button->font = sfFont_createFromFile("assets/fonts/font.otf");
    button->text_pos = (sfVector2f){button->position.x + 60,
    button->position.y + 6};
    button->text_color = sfBlack;
    button->text_size = 30;

    button = set_bucketbutton(button);

    return (button);
}
