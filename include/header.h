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

    void hover_editionmenu(editionmenu_t *menu, sfRenderWindow *window);
    void hover_filemenu(filemenu_t *menu, sfRenderWindow *window);
    void hover_helpmenu(helpmenu_t *menu, sfRenderWindow *window);
    editionmenu_t *init_editionmenu(void);
    filemenu_t *init_filemenu(void);
    helpmenu_t *init_helpmenu(void);
    void display_menu(sfRenderWindow *window, filemenu_t *filemenu,
    editionmenu_t *editionmenu, helpmenu_t *helpmenu);

#endif /* !HEADER_H_ */
