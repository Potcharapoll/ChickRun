#ifndef GAME_H
#define GAME_H
#include "window.h"
#include "player.h"
#include "obstacle.h"
#include "platform.h"

typedef enum {
  START=0,
  INGAME,
  GAMEOVER
}GameState;

typedef struct {
  Player player;
  Obstacle obstacle;
  Platform platform;
  GameState game_state;
}Game;

void startGame(Window* window);
void quitGame(void);
#endif
