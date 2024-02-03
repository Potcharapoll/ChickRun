#include "render.h"

void renderHitBlock(Window* window, SDL_Rect dst) {
  SDL_SetRenderDrawColor(window->renderer, 255,0,255, 255);
  SDL_RenderDrawRect(window->renderer, &dst);
}
