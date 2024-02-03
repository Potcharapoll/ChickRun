#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <SDL2/SDL.h>
#include "window.h"
#include "player.h"

typedef struct {
  SDL_Rect rect;
  SDL_Texture* obstacleTexture;
}Obstacle;

void initObstacle(Window* window);
void updateObstacle(Obstacle* obstacle, Player *player);
void renderObstacle(Window* window, Obstacle* obstacle);
void destroyObstacle(Obstacle* obstacle);
#endif
