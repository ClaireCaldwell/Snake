#pragma once

#include <SDL.h>
#include <iostream>
#include <memory>

#include "snake_tile.h"
#include "helpers.h"

const int WIDTH = 640;
const int HEIGHT = 480;

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();
private:
    SnakeTile m_snake_tile;

    SDL_Window* m_window;
    SDL_Surface* m_window_surface;
    SDL_Event    m_window_event;
};