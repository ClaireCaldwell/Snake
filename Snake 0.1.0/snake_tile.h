#pragma once

#include <SDL.h>
#include "spritesheet.h"

class SnakeTile
{
public:
    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    SnakeTile();
    ~SnakeTile() = default;

    void handle_events(SDL_Event const& event);
    void update(double delta_time);
    void draw(SDL_Surface* window_surface);

private:
    Spritesheet  m_spritesheet;
    int          m_spritesheet_column;
    Direction    m_direction;

    SDL_Rect     m_position;
    double       m_x;
    double       m_y;
};