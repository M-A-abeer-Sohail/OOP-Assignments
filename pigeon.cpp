#include "pigeon.hpp"

void Pigeon::draw(SDL_Renderer *testRenderer, bool pause)
{
    SDL_RenderCopy(testRenderer, assets, &src[frame], &mover);
    if (!pause) // If game is paused frame will increment
    {
        frame++;
    }
    if (frame == 3)
        frame = 0;
}

Pigeon::Pigeon(bool empty) : Unit(empty) {}
Pigeon::Pigeon(SDL_Texture *testTexture)
{
    src[0] = {0, 0, 160, 133};
    src[1] = {0, 133, 160, 133};
    src[2] = {0, 266, 160, 133};
    assets = testTexture;
}
Pigeon::Pigeon()
{
    src[0] = {0, 0, 160, 133};
    src[1] = {0, 133, 160, 133};
    src[2] = {0, 266, 160, 133};
    assets = NULL;
}

// void Pigeon::setTexture(SDL_Renderer *tex)
// {
//     SDL_RenderCopy(tex, assets, &src[frame], &mover);
//     frame++;
//     if (frame == 3)
//         frame = 0;
// }