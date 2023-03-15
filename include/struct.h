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

    typedef struct draw_area {
        sfImage *image;
        sfVector2u img_size;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f scale;
        char *save_path;
    } draw_area_t;

    typedef struct tool {
        int size;
        int shape;
        sfColor color;
    } tool_t;

    typedef struct manage_tools {
        tool_t *pencil;
        tool_t *eraser;
        tool_t *current_tool;
    } manage_tools_t;

    typedef struct less {
        sfRectangleShape *rect;
        sfVector2f pos;
        sfVector2f size;
        sfColor color;
        sfText *text;
        int clicked;
    } less_t;

    typedef struct more {
        sfRectangleShape *rect;
        sfVector2f pos;
        sfVector2f size;
        sfColor color;
        sfText *text;
        int clicked;
    } more_t;

    typedef struct pencil_size {
        sfText *text;
        sfText *tnbr;
        int nbr;
        less_t *less;
        more_t *more;
    } pencil_size_t;

    typedef struct eraser_size {
        sfText *text;
        sfText *tnbr;
        int nbr;
        less_t *less;
        more_t *more;
    } eraser_size_t;

    typedef struct square {
        sfRectangleShape *out;
        sfRectangleShape *form;
        sfVector2f pos;
        sfVector2f size;
        sfColor color;
        int clicked;
    } square_t;

    typedef struct circle {
        sfRectangleShape *out;
        sfCircleShape *form;
        sfVector2f pos;
        sfVector2f size;
        sfColor color;
        int clicked;
    } circle_t;

    typedef struct eraser_shape {
        sfText *text;
        square_t *square;
        circle_t *circle;
        int sf;
    } eraser_shape_t;

    typedef struct pencil_shape {
        sfText *text;
        square_t *square;
        circle_t *circle;
        int sf;
    } pencil_shape_t;

    typedef struct tool_bar {
        sfRectangleShape *rect;
        sfVector2f pos;
        sfVector2f size;
        sfColor color;
        pencil_size_t *pencil_size;
        eraser_size_t *eraser_size;
        pencil_shape_t *pencil_shape;
        eraser_shape_t *eraser_shape;
    } tool_bar_t;

#endif /* !STRUCT_H_ */
