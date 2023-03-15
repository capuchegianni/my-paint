/*
** EPITECH PROJECT, 2023
** PROJECT_BUILDER
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Network.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #include "struct.h"
    #include "my.h"
    #include "my_csfml.h"

    void hover_editionmenu(editionmenu_t *menu, buttonmenu_t *pencilbutton,
    buttonmenu_t *eraserbutton);
    void hover_filemenu(filemenu_t *menu, buttonmenu_t *newfile,
    buttonmenu_t *openfile, buttonmenu_t *savefile);
    void hover_helpmenu(helpmenu_t *menu, buttonmenu_t *about,
    buttonmenu_t *help);
    editionmenu_t *init_editionmenu(void);
    filemenu_t *init_filemenu(void);
    helpmenu_t *init_helpmenu(void);
    void display_menu(sfRenderWindow *window,
    global_filemenu_t *global_filemenu,
    global_editionmenu_t *global_editionmenu,
    global_helpmenu_t *global_helpmenu);
    buttonmenu_t *init_eraserbutton(void);
    int hover_eraserbutton(buttonmenu_t *button);
    buttonmenu_t *init_pencilbutton(void);
    int hover_pencilbutton(buttonmenu_t *button);
    buttonmenu_t *init_newfilebutton(void);
    int hover_newfilebutton(buttonmenu_t *button);
    buttonmenu_t *init_openfilebutton(void);
    int hover_openfilebutton(buttonmenu_t *button);
    buttonmenu_t *init_savefilebutton(void);
    int hover_savefilebutton(buttonmenu_t *button);
    buttonmenu_t *init_aboutbutton(void);
    int hover_aboutbutton(buttonmenu_t *button);
    buttonmenu_t *init_helpbutton(void);
    int hover_helpbutton(buttonmenu_t *button);
    void display_bar(void);
    void base_prints(void);
    buttonmenu_t *init_back(sfVector2f pos, sfVector2f size, int height);
    int hover_back(buttonmenu_t *back);
    void init_area(char **av);
    void draw(void);
    void set_area(int i);
    void outline_area(void);
    void display_about(char *login1, char *login2, buttonmenu_t *back);
    tool_bar_t *tool_bar(void);
    void display_toolbar(tool_bar_t *bar);
    tool_bar_t *pencil_size(tool_bar_t *bar);
    void hover_pencilless(tool_bar_t *bar);
    void hover_pencilmore(tool_bar_t *bar);
    tool_bar_t *eraser_size(tool_bar_t *bar);
    void hover_eraserless(tool_bar_t *bar);
    void hover_erasermore(tool_bar_t *bar);
    void display_colors(void);
    tool_bar_t *pencil_shape(tool_bar_t *bar);
    void hover_pencilsquare(tool_bar_t *bar);
    void hover_pencilcircle(tool_bar_t *bar);
    tool_bar_t *eraser_shape(tool_bar_t *bar);
    void hover_erasersquare(tool_bar_t *bar);
    void hover_erasercircle(tool_bar_t *bar);
    void display_color_text(void);

    extern sfRenderWindow *window;
    extern draw_area_t *area;
    extern manage_tools_t *tools;

#endif /* !HEADER_H_ */
