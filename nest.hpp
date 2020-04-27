#include "unit.hpp"
#pragma once
class Nest : public Unit
{
public:
    Nest(SDL_Texture *, const int, const int); // taking the initial mover arguments through constructor, and updating them using update behavior
    Nest(bool);
    // bool isAdult();
    // Nest(SDL_Texture* tex, SDL_Rect);
};