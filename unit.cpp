#include "unit.hpp"
// #include <SDL.h>

Unit::Unit()
{
}
void Unit::draw(SDL_Renderer *tex)
{
    SDL_RenderCopy(tex, assets, &src, &mover);
}
void Unit::setMover(int xCoord, int yCoord, int width, int height)
{
    mover.x = xCoord;
    mover.y = yCoord;
    mover.w = width;
    mover.h = height;
}
Unit::~Unit()
{
    SDL_DestroyTexture(assets);
    std::cout << "In destructor" << std::endl;
}
