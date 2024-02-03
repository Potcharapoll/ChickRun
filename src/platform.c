#include <stdbool.h>
#include "platform.h"
#include "texture.h"
#include "types.h"
#include "defs.h"

void initPlatform(Window* window, Platform* platform) {
  platform->platformTexture = loadTexture(window, PLATFORM_PATH);
  platform->x               = 0;
  platform->y               = PLATFORM_POSY;
  platform->w               = 640;
  platform->h               = SCALE;
}

void updatePlatform(Platform* platform, Player* player) {
  CollisionDetection(platform, player);
}

void renderPlatform(Window* window, Platform* platform) {
  SDL_Rect platformDst = setRect(platform->x, platform->y, platform->w, platform->h);
  SDL_RenderCopy(window->renderer,platform->platformTexture, NULL , &platformDst); 
} 

void CollisionDetection(Platform* platform, Player* player) {
  f32 PlayerW = SCALE, PlayerH = SCALE;
  f32 PlayerX = player->x, PlayerY = player->y;
  f32 PlatformH = platform->h, PlatformW = platform->w;
  f32 PlatformX = platform->x, PlatformY = platform->y;

  if (PlayerX+PlayerW > PlatformX && PlayerX < PlatformX+PlatformW) {
    if (PlayerY < PlatformY+PlatformH && PlayerY+PlayerH > PlatformY) {
      player->y = PlatformY+PlayerH;
      player->vel_y = 0;
      player->isGrounded = true;
    }
    if (PlayerY+PlayerH > PlatformY && PlayerY < PlatformY) {
      player->y = PlatformY-PlayerH;
      player->vel_y = 0;
      player->isGrounded = true;
    }  
  }
}

void destroyPlatform(Platform* platform) {
  DEBUGTXT("platform->platformTexture destroyed!\n");
  SDL_DestroyTexture(platform->platformTexture);
}
