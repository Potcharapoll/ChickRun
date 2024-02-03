#include "game.h"
#include "ui.h"
#include "defs.h"
#include "player.h"
#include "obstacle.h"
#include "texture.h"
#include "platform.h"
#include <SDL2/SDL_timer.h>

static Game game;
static Player player;
static Platform platform;
static Obstacle obstacle;

static void setup(Window* window) {
  game.game_state = START;
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
            if (game.game_state == START) {
              destroyStartScreen();
              game.game_state = INGAME;
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
  if (game.game_state == INGAME && !player.isDeath) {
    updateIngameUI(window, &player);
    updatePlatform(&platform, &player);
    updatePlayer(&player);
    updateObstacle(&obstacle, &player);
  }
}

static void render(Window* window) {
  SDL_RenderClear(window->renderer);
  if (game.game_state == START) {
    renderStartScreenUI(window);
  } else if (game.game_state == INGAME) {
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
