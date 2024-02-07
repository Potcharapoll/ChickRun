#include "player.h"
#include "texture.h"
#include "defs.h"
#ifdef DEBUG
#include "render.h"
#endif

void initPlayer(Window* window, Player* player) {
  player->texture         = loadTexture(window, PLAYER_PATH);
  player->x               = 30;
  player->y               = 0;
  player->dy              = 0;
  player->dx              = 0;
  player->scoreMultiplier = 1.0F;
  player->jump_time       = JUMP_TIME;
  player->jump_force      = JUMP_FORCE;
  player->isGrounded      = false;
  player->isDeath         = false;
  player->isJumping       = false;
}

void renderPlayer(Window* window, Player* player) {
  SDL_Rect dst = setRect(player->x, player->y, SCALE, SCALE);
  SDL_RenderCopy(window->renderer, player->texture, NULL, &dst);
  #ifdef DEBUG
  renderHitBlock(window, dst);
  #endif
}

void updatePlayer(Player* player) { 
  if (!player->isDeath) {
    player->score+=1.0f*player->scoreMultiplier;
  }
  if (!player->isGrounded) {
    player->dy += GRAVITY;
  }
  player->y += player->dy;
  player->scoreMultiplier += 0.0001f;
  DEBUGTXT("PY: %.2f DY: %.2f IG: %d IJ: %d\n", player->y, player->dy, player->isGrounded, player->isJumping);
}

void controlPlayer(Player* player) {
  const Uint8 * state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_W] && player->isGrounded) {
    player->dy = -5.0f;
    player->isJumping = true;
    player->isGrounded = false;
  } 
  else if (state[SDL_SCANCODE_W] && player->isJumping && player->jump_time > 0.000f) {
    player->dy -= player->jump_force;
    player->jump_time--;
  } 
  else {
    player->jump_time = JUMP_TIME;
    player->isJumping = false;
  }
}

void destroyPlayer(Player* player) {
  DEBUGTXT("player->texture destroyed!\n");
  SDL_DestroyTexture(player->texture);
}
