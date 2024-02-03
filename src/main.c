#include "game.h"
#include "window.h"


static Window window;

void cleanup() {
  destroyWindow(&window);
}

int main(void) {
  atexit(cleanup);
  if (0 == initWindow(&window))
    startGame(&window);
  else {
    SDL_Log("Failed to initialize program!\n");
    exit(1);
  }
  return 0;
}
