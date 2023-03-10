/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-mypaint-gianni.henriques
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "header.h"

    typedef struct filemenu {
        sfRectangleShape *rect;
        sfVector2f position;
        sfVector2f size;
        sfColor color;
        sfText *text;
        sfFont *font;
        sfVector2f text_pos;
        sfColor text_color;
        int text_size;
        int hover;
        int clicked;
        int released;
    } filemenu_t;

    typedef struct editionmenu {
        sfRectangleShape *rect;
        sfVector2f position;
        sfVector2f size;
        sfColor color;
        sfText *text;
        sfFont *font;
        sfVector2f text_pos;
        sfColor text_color;
        int text_size;
        int hover;
        int clicked;
        int released;
    } editionmenu_t;

    typedef struct helpmenu {
        sfRectangleShape *rect;
        sfVector2f position;
        sfVector2f size;
        sfColor color;
        sfText *text;
        sfFont *font;
        sfVector2f text_pos;
        sfColor text_color;
        int text_size;
        int hover;
        int clicked;
        int released;
    } helpmenu_t;

#endif /* !STRUCT_H_ */
