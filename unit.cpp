#include "unit.hpp"
// #include <SDL.h>

Unit::Unit()
{
}
Unit::Unit(bool empty) : emptyBit(true){};

void Unit::draw(SDL_Renderer *testRenderer)
{
    SDL_RenderCopy(testRenderer, assets, &src, &mover);
}
void Unit::setMover(int xCoord, int yCoord, int width, int height)
{
    mover.x = xCoord;
    mover.y = yCoord;
    mover.w = width;
    mover.h = height;
}
int *Unit::getMover()
{
    int *result = new int[4];
    result[0] = mover.x;
    result[1] = mover.y;
    result[2] = mover.w;
    result[3] = mover.h;

    return result;
}
Unit::~Unit()
{
    SDL_DestroyTexture(assets);
    std::cout << "In destructor" << std::endl;
}
