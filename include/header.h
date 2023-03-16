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
    #include <math.h>

    #include "struct.h"
    #include "my.h"
    #include "my_csfml.h"

    // Init structs

    filemenu_t *init_filemenu(void);
    editionmenu_t *init_editionmenu(void);
    helpmenu_t *init_helpmenu(void);
    buttonmenu_t *init_newfilebutton(void);
    buttonmenu_t *init_openfilebutton(void);
    buttonmenu_t *init_savefilebutton(void);
    buttonmenu_t *init_eraserbutton(void);
    buttonmenu_t *init_pencilbutton(void);
    buttonmenu_t *init_bucketbutton(void);
    buttonmenu_t *init_aboutbutton(void);
    buttonmenu_t *init_helpbutton(void);
    buttonmenu_t *init_back(sfVector2f pos, sfVector2f size, int height);
    void init_area(char **av);

    // Hover & Click

    void hover_editionmenu(editionmenu_t *menu, buttonmenu_t *pencilbutton,
    buttonmenu_t *eraserbutton, buttonmenu_t *bucketbutton);
    void hover_filemenu(filemenu_t *menu, buttonmenu_t *newfile,
    buttonmenu_t *openfile, buttonmenu_t *savefile);
    void hover_helpmenu(helpmenu_t *menu, buttonmenu_t *about,
    buttonmenu_t *help);
    int hover_eraserbutton(buttonmenu_t *button);
    int hover_pencilbutton(buttonmenu_t *button);
    int hover_newfilebutton(buttonmenu_t *button);
    int hover_openfilebutton(buttonmenu_t *button);
    int hover_savefilebutton(buttonmenu_t *button);
    int hover_aboutbutton(buttonmenu_t *button);
    int hover_helpbutton(buttonmenu_t *button);
    int hover_back(buttonmenu_t *back);
    void hover_pencilless(tool_bar_t *bar);
    void hover_pencilmore(tool_bar_t *bar);
    void hover_eraserless(tool_bar_t *bar);
    void hover_erasermore(tool_bar_t *bar);
    void hover_pencilsquare(tool_bar_t *bar);
    void hover_pencilcircle(tool_bar_t *bar);
    void hover_erasersquare(tool_bar_t *bar);
    void hover_erasercircle(tool_bar_t *bar);
    int hover_bucketbutton(buttonmenu_t *button);

    // Display

    void display_menu(sfRenderWindow *window,
    global_filemenu_t *global_filemenu,
    global_editionmenu_t *global_editionmenu,
    global_helpmenu_t *global_helpmenu);
    void display_bar(void);
    void display_about(char *login1, char *login2, buttonmenu_t *back);
    void display_toolbar(tool_bar_t *bar);
    void display_colors(void);
    void display_color_text(void);

    // Toolbar buttons

    tool_bar_t *tool_bar(void);
    tool_bar_t *pencil_size(tool_bar_t *bar);
    tool_bar_t *eraser_size(tool_bar_t *bar);
    tool_bar_t *pencil_shape(tool_bar_t *bar);
    tool_bar_t *eraser_shape(tool_bar_t *bar);

    // Drawing

    void draw(void);
    void set_area(int i);
    void outline_area(void);
    void draw_square(sfVector2i mouse_pos, sfVector2f area_pos,
    double y_ratio, double x_ratio);
    void draw_circle(sfVector2i mouse_pos, sfVector2f area_pos,
    double y_ratio, double x_ratio);
    void init_tools(void);
    void color_picker_cursor(double x_ratio, double y_ratio);

    // Little things

    void base_prints(void);
    void choose_cursor(double x_ratio, double y_ratio);

    // Extern variables

    extern sfRenderWindow *window;
    extern draw_area_t *area;
    extern manage_tools_t *tools;

#endif /* !HEADER_H_ */
