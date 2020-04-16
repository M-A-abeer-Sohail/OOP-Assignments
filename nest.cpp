#include "nest.hpp"
#pragma once

Nest::Nest(SDL_Texture *testTexture)
{
    src = {175, 200, 445 - 175, 406 - 200};
    assets = testTexture;
}
Nest::Nest(bool empty) : Unit(empty) {}
