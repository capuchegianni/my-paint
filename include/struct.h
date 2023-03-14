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

#endif /* !STRUCT_H_ */
