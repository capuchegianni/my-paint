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
        int pressed;
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
        int pressed;
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
        int pressed;
    } helpmenu_t;

    typedef struct button_menu {
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
        int pressed;
    } buttonmenu_t;

    typedef struct global_filemenu {
        filemenu_t *filemenu;
        buttonmenu_t *newfile;
        buttonmenu_t *openfile;
        buttonmenu_t *savefile;
    } global_filemenu_t;

    typedef struct global_editionmenu {
        editionmenu_t *editionmenu;
        buttonmenu_t *eraser;
        buttonmenu_t *pencil;
    } global_editionmenu_t;

    typedef struct global_helpmenu {
        helpmenu_t *helpmenu;
        buttonmenu_t *about;
        buttonmenu_t *help;
    } global_helpmenu_t;

#endif /* !STRUCT_H_ */
