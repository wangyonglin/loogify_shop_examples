#ifndef FFMPEG_PLAYER_H
#define FFMPEG_PLAYER_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class FFmpegPlayer  
{
public:
    FFmpegPlayer(SDL_Renderer *renderer=nullptr);
    ~FFmpegPlayer();

public:
    void play();
    SDL_Texture *drew(const SDL_Rect *srcrect, const SDL_Rect *dstrect);

private:
SDL_Renderer *renderer=nullptr;
SDL_Texture* texture_head =nullptr;
};

#endif