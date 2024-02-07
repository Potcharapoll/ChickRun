#include "obstacle.h"
#include "texture.h"
#include "types.h"
#include "defs.h"
#ifdef DEBUG
#include "render.h"
#endif

static SDL_Texture *singleChick;
static SDL_Texture *doubleChick;
static SDL_Rect playerDst;
static SDL_Rect obstacleDst;

static void setObstaclePos(u8 idx, Obstacle* self) {
  switch (idx) {
    case 0:
      self->obstacleTexture = singleChick;
      self->rect = setRect(WINDOW_WIDTH+SCALE, OBSTACLE_POSY, SCALE, SCALE);
      break;
    case 1:
      self->obstacleTexture = doubleChick;
      self->rect = setRect(WINDOW_WIDTH+SCALE, OBSTACLE_POSY, SCALE+SCALE/3, SCALE);
      break;
    default:
      perror("Invalid obstacle value!");
      break;
  }
}

void initObstacle(Window* window) {
  singleChick = loadTexture(window, SINGLE_OBSTACLE_PATH);
  doubleChick = loadTexture(window, DOUBLE_OBSTACLE_PATH);
}

void renderObstacle(Window* window, Obstacle* obstacle) {
  SDL_RenderCopy(window->renderer, obstacle->obstacleTexture, NULL, &obstacle->rect);
  #ifdef DEBUG
  renderHitBlock(window, obstacle->rect);
  #endif
}

void updateObstacle(Obstacle* obstacle, Player* player) {
  obstacle->rect.x-=5.0f;
  if (obstacle->rect.x+obstacle->rect.w < 0) {
    srand(SDL_GetTicks());
    setObstaclePos(rand()%2,obstacle);
  }

  playerDst = setRect(player->x, player->y,SCALE,SCALE);
  obstacleDst = setRect(obstacle->rect.x, obstacle->rect.y, obstacle->rect.w, obstacle->rect.h);
  if (SDL_HasIntersection(&playerDst, &obstacleDst)) {
    player->isDeath = true;
  }
}

void destroyObstacle(Obstacle* obstacle) {
  DEBUGTXT("obstacle->obstacleTexture destroyed!\n");
  SDL_DestroyTexture(obstacle->obstacleTexture);
}
