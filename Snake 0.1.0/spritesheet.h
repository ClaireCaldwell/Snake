#pragma once

#include <SDL.h>
#include "helpers.h"

class Spritesheet
{
public:
    Spritesheet(char const* path, int row, int column);
    ~Spritesheet();

    void select_sprite(int x, int y);
    void draw_selected_sprite(SDL_Surface* window_surface, SDL_Rect* position);

private:
    SDL_Rect     m_clip;
    SDL_Surface* m_spritesheet_image;

    int m_start_x;
    int m_start_y;
};