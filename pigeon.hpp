#pragma once
#include "unit.hpp"
class Pigeon : public Unit
{
    int eggsLaid;    //no. of eggs laid
    bool baby;       // is it a baby pigeon?
    SDL_Rect src[3]; // three textures, to make the fly animation
    int frame = 0;

public:
    Pigeon();
    Pigeon(SDL_Texture *);
    // Pigeon(SDL_Texture *, SDL_Rect);
    // Pigeon(SDL_Texture *, SDL_Rect, bool);
    void draw(SDL_Renderer *, bool);
    bool layEgg();
    bool isAlive();
    //void setTexture(SDL_Renderer *);
};
