#include "SDL.h"
#include <iostream>


// Dimensions for pigeon are 50,50
// Dimensions for nest are 60,75
// Dimensions for egg are 27,29

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
    Unit(const int, const int, const int, const int);
    // Unit(SDL_Texture *);
    virtual void draw(SDL_Renderer *);
    // virtual bool isAdult() = 0;
    virtual void updateBehavior(const int, const int); // Takes in the window dimensions
    virtual ~Unit();
};