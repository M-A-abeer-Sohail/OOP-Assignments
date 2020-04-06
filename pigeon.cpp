#include "pigeon.hpp"

void Pigeon::draw(SDL_Renderer *render)
{
    SDL_RenderCopy(render, assets, &src[frame], &mover);
    frame++;
    if (frame == 3)
        frame = 0;
}

Pigeon::Pigeon(SDL_Texture *tex)
{
    src[0] = {0, 0, 160, 133};
    src[1] = {0, 133, 160, 133};
    src[2] = {0, 266, 160, 133};
    assets = tex;
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