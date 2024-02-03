#ifndef UI_H
#define UI_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "defs.h"
#include "types.h"
#include "player.h"

typedef struct {
  char txt[MAXLEN];
  SDL_Texture* texture;
  TTF_Font* font;
  SDL_Rect dst;
}Text;

void initUI(Window* window);
void renderScore(void);
void renderIngameUI(Window* window);
void updateIngameUI(Window* window, Player* player);
void renderStartScreenUI(Window* window);
void renderGameOver(Window* window);
void destroyStartScreen(void);
void destroyUI(void);

#endif
