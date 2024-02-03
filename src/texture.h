#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include "window.h"
#include "types.h"
#include "ui.h"

void initTexture(void);
void destroyTexture(void); 
void loadTextTexture(Window* window, Text* txt);
SDL_Texture *loadTexture(Window* window, const char* path);
SDL_Rect setRect(s32 x, s32 y, s32 w, s32 h);
#endif
