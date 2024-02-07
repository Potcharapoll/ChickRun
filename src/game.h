#ifndef GAME_H
#define GAME_H
#include "window.h"

typedef enum {
  START=0,
  INGAME,
  GAMEOVER
}GameState;

void startGame(Window* window);
void quitGame(void);
#endif
