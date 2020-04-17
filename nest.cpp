#include "nest.hpp"
#pragma once

Nest::Nest(SDL_Texture *testTexture, const int &xCoord,
           const int &yCoord, const int &width, const int &height)
// taking the initial mover arguments through constructor, and updating them using update behavior
{
    src = {175, 200, 445 - 175, 406 - 200};
    assets = testTexture;
}
Nest::Nest(bool empty) : Unit(empty) {}
