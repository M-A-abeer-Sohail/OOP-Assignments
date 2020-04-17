#include "egg.hpp"

Egg::Egg(SDL_Texture *testRenderer,
         const int &xCoord, const int &yCoord,
         const int &width, const int &height);
// taking the initial mover arguments through constructor, and updating them using update behavior
{
    src = {175, 0, 445 - 175, 200};
    assets = testRenderer;
}