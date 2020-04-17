#include "unit.hpp"
#pragma once

class Egg : public Unit
{
public:
    Egg(SDL_Texture *, const int &, const int &, const int &, const int &); // taking the initial mover arguments through constructor, and updating them using update behavior
    // Egg(SDL_Texture*, SDL_Rect);
    // void draw(SDL_Renderer*);
    // bool dropped();
};