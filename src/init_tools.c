/*
** EPITECH PROJECT, 2023
** my_paint-branch
** File description:
** init_tools
*/

#include "../include/header.h"

void init_pencil(void)
{
    tools = malloc(sizeof(manage_tools_t));
    tools->pencil = malloc(sizeof(tool_t));
    tools->pencil->size = 5;
    tools->pencil->color = sfBlack;
    tools->pencil->shape = 0;
    tools->pencil->texture = sfTexture_createFromFile
    ("assets/images/pencil.png", NULL);
}

void init_eraser(void)
{
    tools->eraser = malloc(sizeof(tool_t));
    tools->eraser->size = 5;
    tools->eraser->color = sfWhite;
    tools->eraser->shape = 0;
    tools->eraser->texture = sfTexture_createFromFile
    ("assets/images/eraser.png", NULL);
}

void init_bucket(void)
{
    tools->bucket = malloc(sizeof(tool_t));
    tools->bucket->size = 5000;
    tools->bucket->color = sfBlack;
    tools->bucket->texture = sfTexture_createFromFile
    ("assets/images/bucket.png", NULL);
}

void init_color_picker(void)
{
    tools->color_picker = malloc(sizeof(tool_t));
    tools->color_picker->texture = sfTexture_createFromFile
    ("assets/images/color_picker.png", NULL);
}

void init_tools(void)
{
    init_pencil();
    init_eraser();
    init_bucket();
    init_color_picker();

    tools->current_tool = malloc(sizeof(tool_t));
    tools->current_tool = tools->pencil;
}
