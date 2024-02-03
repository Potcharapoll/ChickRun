#include "window.h"
#include "defs.h"
#include "game.h"

int initWindow(Window* window) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("Failed to initialize SDL!\n");
    SDL_Log("%s\n", SDL_GetError());
    exit(1);
  } else {
    SDL_Log("SDL initialized!\n");
  }
  window->window = SDL_CreateWindow("ChickRun",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!window->window) {
    SDL_Log("Failed to create window!\n");
    SDL_Log("%s\n", SDL_GetError());
    exit(1);
  } else {
    SDL_Log("Create window successfully!\n");
  }
  window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
  if (!window->renderer) {
    SDL_Log("Failed to create renderer!\n");
    SDL_Log("%s\n", SDL_GetError());
    exit(1);
  } else {
    SDL_Log("Create renderer successfully!\n");
  }
  return 0;
}

void destroyWindow(Window* window) {
  SDL_Log("Cleaning up program!\n");
  quitGame();

  DEBUGTXT("destroy windoe->renderer\n");
  SDL_DestroyRenderer(window->renderer);
  
  DEBUGTXT("destroy windoe->window\n");
  SDL_DestroyWindow(window->window);

  DEBUGTXT("Quit SDL\n");
  SDL_Quit();
}
