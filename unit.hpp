#include "SDL.h"
#include <iostream>

#pragma once
class Unit
{
protected:
    SDL_Texture *assets;
    SDL_Rect src;
    SDL_Rect mover;
    bool emptyBit;
    void setMover(int x, int y, int width, int height);
    void setMover(int, int);
    int *getMover();

public:
    Unit();
    Unit(bool);
    // Unit(SDL_Texture *);
    virtual void draw(SDL_Renderer *);
    // virtual bool isAdult() = 0;
    virtual void updateBehavior(const int, const int); // Takes in the window dimensions

    virtual ~Unit();
};