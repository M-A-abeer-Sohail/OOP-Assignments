#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>

#include "pigeon.hpp"
#include "egg.hpp"
#include "nest.hpp"
#include "unit.hpp"
using namespace std;

class Game
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    //Current displayed texture
    SDL_Texture *gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture *assets = NULL;

    SDL_Texture *viewportTextures[2] = {NULL, NULL};

    //You may use C++ linked lists, or you can create your own.

    // list<Pigeon*> pigeons;
    // list<Egg*> eggs;
    // list<Nest*> nests;

public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    bool titleScreen();
    void run();
    void updateEggs();
    void updatePigeons();
    void drawAllObjects();
};
