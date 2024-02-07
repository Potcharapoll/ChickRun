#ifndef PLATFORM_H
#define PLATFORM_H
#include <SDL2/SDL.h>
#include "window.h"
#include "player.h"
#include "types.h"

typedef struct {
  SDL_Texture* platformTexture;
  f32 x, y, w, h;
}Platform;

enum Level {
  GRASS_LEVEL = 0,
  CAVE_LEVEL
};

void initPlatform(Window* window, Platform* platform);
void updatePlatform(Platform* platform, Player* player);
void renderPlatform(Window* window, Platform* platform);
void switchLevel(Platform* platform);
void CollisionDetection(Platform* platform, Player* player);
void destroyPlatform(Platform* platform);
#endif
