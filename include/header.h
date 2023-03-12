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
    void display_menu(sfRenderWindow *window, filemenu_t *filemenu,
    editionmenu_t *editionmenu, helpmenu_t *helpmenu);
    buttonmenu_t *init_eraserbutton(void);
    void hover_eraserbutton(buttonmenu_t *button);
    buttonmenu_t *init_pencilbutton(void);
    void hover_pencilbutton(buttonmenu_t *button);
    buttonmenu_t *init_newfilebutton(void);
    void hover_newfilebutton(buttonmenu_t *button);
    buttonmenu_t *init_openfilebutton(void);
    void hover_openfilebutton(buttonmenu_t *button);
    buttonmenu_t *init_savefilebutton(void);
    void hover_savefilebutton(buttonmenu_t *button);
    buttonmenu_t *init_aboutbutton(void);
    void hover_aboutbutton(buttonmenu_t *button);
    buttonmenu_t *init_helpbutton(void);
    void hover_helpbutton(buttonmenu_t *button);

    extern sfRenderWindow *window;

#endif /* !HEADER_H_ */
