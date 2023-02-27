/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-gianni.henriques
** File description:
** my_play_sound
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_csfml_lib.h"
#include "../../include/my.h"
#include <stdio.h>

void window_is_closed(sfRenderWindow *window, sfMusic *music)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)
        && event.type == sfEvtClosed) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
}

int my_play_sound(sfRenderWindow *window, char *path)
{
    sfMusic *music;
    int music_status = 0;

    if (sfRenderWindow_isOpen(window) == sfTrue) {
        if ((music = sfMusic_createFromFile(path)) == NULL)
            return 84;
        if (music_status == 0) {
            sfMusic_play(music);
            sfMusic_setLoop(music, sfTrue);
            music_status = 1;
        }
    }
}
