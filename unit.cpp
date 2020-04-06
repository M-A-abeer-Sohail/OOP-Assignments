#include "unit.hpp"
// #include <SDL.h>

Unit::Unit()
{
}
Unit::void draw(SDL_Renderer *tex)
{
    SDL_RenderCopy(tex, &assets, &src, &mover);
}
Unit::SDL_Rect getMover(int xCoord, int yCoord, int width, int height)
{
    mover.x = xCoord;
    mover.y = yCoord;
    mover.w = width;
    mover.h = height;
}
Unit::~Unit()
{
    SDL_DestroyTexture(assets);
}
