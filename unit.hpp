#include "SDL.h"
#pragma once
class Unit
{
protected:
    SDL_Texture *assets;
    SDL_Rect src;
    SDL_Rect mover;

public:
    Unit();
    // Unit(SDL_Texture *);
    virtual void draw(SDL_Renderer *);
    void setMover(int x, int y, int width, int height);

    ~Unit();
};