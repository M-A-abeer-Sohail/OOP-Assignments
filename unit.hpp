#include "SDL.h"
#include <iostream>

#pragma once
class Unit
{
protected:
    SDL_Texture *assets;
    SDL_Rect src;
    SDL_Rect mover;
    void setMover(int x, int y, int width, int height);
    bool emptyBit;

public:
    Unit();
    Unit(bool);
    // Unit(SDL_Texture *);
    virtual void draw(SDL_Renderer *);

    ~Unit();
};