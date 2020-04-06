#include "egg.hpp"

Egg::Egg(SDL_Texture *testRenderer)
{
    src = {175, 0, 445 - 175, 200};
    assets = testRenderer;
}