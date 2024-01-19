#include "snake_tile.h"

int const SPRITESHEET_UP = 0;
int const SPRITESHEET_LEFT = 1;
int const SPRITESHEET_RIGHT = 2;
int const SPRITESHEET_DOWN = 3;

SnakeTile::SnakeTile() : m_spritesheet("C:\\Users\\clair\\OneDrive\\Professional\\Snake\\poop.bmp", 1, 2)
{
    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 16;
    m_position.h = 16;

    m_x = 0.0;
    m_y = 0.0;

    m_direction = Direction::NONE;

    m_spritesheet.select_sprite(1, 1);
    m_spritesheet_column = 1;
}

void SnakeTile::handle_events(SDL_Event const& event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        Uint8 const* keys = SDL_GetKeyboardState(nullptr);

        if (keys[SDL_SCANCODE_W] == 1 || keys[SDL_SCANCODE_UP] == 1)
            m_direction = Direction::UP;
        else if (keys[SDL_SCANCODE_S] == 1 || keys[SDL_SCANCODE_DOWN] == 1)
            m_direction = Direction::DOWN;
        else if (keys[SDL_SCANCODE_A] == 1 || keys[SDL_SCANCODE_LEFT] == 1)
            m_direction = Direction::LEFT;
        else if (keys[SDL_SCANCODE_D] == 1 || keys[SDL_SCANCODE_RIGHT] == 1)
            m_direction = Direction::RIGHT;
        break;
    }
}

void SnakeTile::update(double delta_time)
{
    switch (m_direction)
    {
        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            break;

        case Direction::UP:
            m_y = m_y - (125.0 * delta_time);
            break;

        case Direction::DOWN:
            m_y = m_y + (125.0 * delta_time);
            break;

        case Direction::LEFT:
            m_x = m_x - (125.0 * delta_time);
            break;

        case Direction::RIGHT:
            m_x = m_x + (125.0 * delta_time);
            break;
    }

    m_position.x = m_x;
    m_position.y = m_y;

    if (m_spritesheet_column > 2)
        m_spritesheet_column = 1;
}

void SnakeTile::draw(SDL_Surface* window_surface)
{
    m_spritesheet.draw_selected_sprite(window_surface, &m_position);
    SDL_Delay(10);
}