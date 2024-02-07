#include "game.h"
#include "defs.h"
#include "player.h"
#include "obstacle.h"
#include "texture.h"
#include "platform.h"

static GameState gameState;
static Player player;
static Platform platform;
static Obstacle obstacle;

static void setup(Window* window) {
  gameState = START;
  initTexture();
  initUI(window);
  initObstacle(window);
  initPlatform(window, &platform);
  initPlayer(window, &player);
  DEBUGTXT("Setup finished!\n");
}

static void processInput(Window* window) {
  while (SDL_PollEvent(&window->event)) {
    switch (window->event.type) {
      case SDL_QUIT:
        window->quit = true;
        break;
      case SDL_KEYDOWN:
        switch(window->event.key.keysym.sym) {
          case SDLK_SPACE:
            if (gameState == START) {
              destroyStartScreen();
              gameState = INGAME;
            }
            break;
          case SDLK_ESCAPE:
            window->quit = true;
            break;
        }
        break;
    }
  }
  controlPlayer(&player);
}

static void update(Window* window) {
  if (gameState == INGAME && !player.isDeath) {
    updateIngameUI(window, &player);
    updatePlatform(&platform, &player);
    updatePlayer(&player);
    updateObstacle(&obstacle, &player);
  }
}

static void render(Window* window) {
  SDL_RenderClear(window->renderer);
  if (gameState == START) {
    renderStartScreenUI(window);
  } 
  else if (gameState == INGAME) {
    renderIngameUI(window);
    renderPlatform(window, &platform);
    renderPlayer(window, &player);
    renderObstacle(window, &obstacle);
    if (player.isDeath) {
      renderGameOver(window);
    }
  }
  SDL_RenderPresent(window->renderer);
}

void startGame(Window* window) {
  setup(window);
  while (!window->quit) {
    processInput(window);
    update(window);
    render(window);
    SDL_Delay(16);
  }
}

void quitGame(void) {
  DEBUGTXT("Destroy UI!\n");
  destroyUI();

  DEBUGTXT("Destroy Player!\n");
  destroyPlayer(&player);

  DEBUGTXT("Destroy Obstacle!\n");
  destroyObstacle(&obstacle);

  DEBUGTXT("Destroy Platform!\n");
  destroyPlatform(&platform);

  DEBUGTXT("Destroy Texture!\n");
  destroyTexture();
}
