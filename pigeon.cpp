#include "pigeon.hpp"

Pigeon::Pigeon(bool empty) : Unit(empty) {}
Pigeon::Pigeon(SDL_Texture *testTexture, const int &xCoord,
               const int &yCoord, const int &width, const int &height, const int &maxH)
    : maxHeight(maxH), baby(true) // in birthing a baby pigeon
{
    src[0] = {0, 0, 160, 133};
    src[1] = {0, 133, 160, 133};
    src[2] = {0, 266, 160, 133};
    assets = testTexture;
}
Pigeon::Pigeon(SDL_Texture *testTexture,
               const int &xCoord, const int &yCoord,
               const int &width, const int &height) // in creating regular pigeon
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

void Pigeon::draw(SDL_Renderer *testRenderer, bool pause)
{
    SDL_RenderCopy(testRenderer, assets, &src[frame], &mover);
    if (!pause) // If game is paused frame will not increment
    {
        frame++;
    }
    if (frame == 3)
        frame = 0;
}
void Pigeon::updateBehavior(const int WINDOW_WIDTH, const int WINDOW_HEIGHT)
{
    if (baby)
    {
        int *pos = getMover();
        if (pos[2] == maxHeight || pos[3] == (maxHeight / 2))
        {
            baby = false;
        }
        if (pos[0] == WINDOW_WIDTH)
        {
            if (pos[1] == WINDOW_WIDTH)
            {
            }
        }
    }
}

// void Pigeon::setTexture(SDL_Renderer *tex)
// {
//     SDL_RenderCopy(tex, assets, &src[frame], &mover);
//     frame++;
//     if (frame == 3)
//         frame = 0;
// }