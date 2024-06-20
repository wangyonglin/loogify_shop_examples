#include "FFmpegPlayer.h"

FFmpegPlayer::FFmpegPlayer(SDL_Renderer *renderer)
:renderer(renderer)
{
  texture_head = IMG_LoadTexture(renderer, "data/head.png");
}


FFmpegPlayer::~FFmpegPlayer()
{
    SDL_DestroyTexture(texture_head);
}

void FFmpegPlayer::play()
{
    printf("DDDDD\n");
}

SDL_Texture *FFmpegPlayer::drew(const SDL_Rect * srcrect,
                                           const SDL_Rect * dstrect)
{
    SDL_RenderCopy(renderer, texture_head, srcrect, dstrect);
    return texture_head;
}

