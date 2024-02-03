#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "texture.h"
#include "defs.h"
#include "types.h"

static SDL_Surface     *surface;
static const SDL_Color white = {255,255,255,255};

SDL_Texture * loadTexture(Window* window, const char* path) {
  surface = IMG_Load(path);
  if (!surface) {
    SDL_Log("Failed to load '%s'\n", path);
  } else {
    SDL_Log("'%s' Loaded!\n", path);
  } 
  SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, surface);
  return texture;
}

SDL_Rect setRect(s32 x, s32 y, s32 w, s32 h) {
  SDL_Rect rect = {.x = x, .y = y, .w = w, .h = h};
  return rect;
}

void loadTextTexture(Window* window, Text* txt) {
  surface = TTF_RenderText_Solid(txt->font, txt->txt, white);
  txt->texture = SDL_CreateTextureFromSurface(window->renderer, surface);
}

void initTexture(void) {
  s32 flags = IMG_INIT_PNG;
  s32 initted = IMG_Init(flags);
  if ((initted & flags) != flags) {
    SDL_Log("Failed to initialize png!\n");
  } else {
    SDL_Log("PNG initialized!");
  }
}

void destroyTexture(void) {
  DEBUGTXT("Destroy surface!\n");
  SDL_FreeSurface(surface);

  DEBUGTXT("Quit IMG!\n");
  IMG_Quit();
}
