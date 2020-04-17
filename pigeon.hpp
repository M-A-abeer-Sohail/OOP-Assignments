#pragma once
#include "unit.hpp"
class Pigeon : public Unit
{
    int eggsLaid;    //no. of eggs laid
    bool baby;       // is it a baby pigeon?
    SDL_Rect src[3]; // three textures, to make the fly animation
    int frame = 0;
    int threshold;

public:
    Pigeon();
    Pigeon(bool);
    Pigeon(SDL_Texture *, int);
    // Pigeon(SDL_Texture *, SDL_Rect);
    // Pigeon(SDL_Texture *, SDL_Rect, bool);
    void draw(SDL_Renderer *, bool);
    bool layEgg();
    bool isAlive();
    void updateBehavior();
    // bool isAdult();
    //void setTexture(SDL_Renderer *);
};
