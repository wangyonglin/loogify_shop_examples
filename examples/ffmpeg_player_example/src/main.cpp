#include <memory>
#include "FFmpegPlayer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#undef main

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error: %s", SDL_GetError());
		return -1;
	}
	// 为了显示png图片，额外使用了图片库，所以要单独初始化
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_Window *window = SDL_CreateWindow("Spine SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	if (!window)
	{
		printf("Error: %s", SDL_GetError());
		return -1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		printf("Error: %s", SDL_GetError());
		return -1;
	}

	std::unique_ptr<FFmpegPlayer> ffmpeg = std::make_unique<FFmpegPlayer>(renderer);
	ffmpeg->play();

	bool quit = false;
	uint64_t lastFrameTime = SDL_GetPerformanceCounter();
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 94, 93, 96, 255);
		SDL_RenderClear(renderer);

		// uint64_t now = SDL_GetPerformanceCounter();
		// double deltaTime = (now - lastFrameTime) / (double)SDL_GetPerformanceFrequency();
		// lastFrameTime = now;

		ffmpeg->drew(NULL,NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	//退出image库
 	IMG_Quit();
	SDL_Quit();
	return 0;
}
