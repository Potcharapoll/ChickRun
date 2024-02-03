#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "types.h"

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event event;
  bool quit;
}Window;

int  initWindow(Window *window);
void destroyWindow(Window *window);
#endif
