#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "window.h"
#include "types.h"

typedef struct {
  SDL_Texture* texture;
  f32 x, y, vel_x, vel_y;
  f32 jump_time, jump_force;
  f64 score, scoreMultiplier;
  bool isGrounded, isJumping, isDeath;
}Player;

void initPlayer(Window* window,Player* player);
void renderPlayer(Window* window, Player* player);
void updatePlayer(Player* player);
void destroyPlayer(Player* player);
void controlPlayer(Player* player);
#endif
