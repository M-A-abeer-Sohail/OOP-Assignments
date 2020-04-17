#pragma once
#include "unit.hpp"
class Pigeon : public Unit
{
    int eggsLaid;    //no. of eggs laid
    bool baby;       // is it a baby pigeon?
    SDL_Rect src[3]; // three textures, to make the fly animation
    int frame = 0;
    int maxHeight; // it is the maximum height pigeon can fly to, if it is born out ouf nest

public:
    Pigeon();
    Pigeon(bool);
    Pigeon(SDL_Texture *, const int &, const int &, const int &, const int &, const int &);
    Pigeon(SDL_Texture *, const int &, const int &, const int &, const int &);
    // Pigeon(SDL_Texture *, SDL_Rect);
    // Pigeon(SDL_Texture *, SDL_Rect, bool);
    void draw(SDL_Renderer *, bool);
    bool layEgg();
    // bool isAlive();
    void updateBehavior(const int &, const int &);
    // bool isAdult();
    //void setTexture(SDL_Renderer *);
};
