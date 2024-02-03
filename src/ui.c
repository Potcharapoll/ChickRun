#include "ui.h"
#include "defs.h"
#include "window.h"
#include "texture.h"
#include <SDL2/SDL_ttf.h>

static TTF_Font     *FONT;
static Text         *scoreTxt[2];
static Text         *startScreenTxt[2];
static Text         *gameOverTxt;
static SDL_Texture  *startScreen;
static SDL_Texture  *inGameScreen;

static Text* setProperties(SDL_Rect dst, TTF_Font *font, const char* txt) {
  Text* tmp = (Text*)malloc(sizeof(Text));
  tmp->dst = dst;
  tmp->font = font;
  strcpy(tmp->txt, txt);
  return tmp;
}

void initUI(Window* window) {
  if (TTF_Init() < 0) {
    SDL_Log("Failed to initialize TTF!\n");
    exit(1);
  } else {
    SDL_Log("TTF initialized!\n");
  }
  FONT = TTF_OpenFont(FONTPATH, FONTSIZE);
  if (!FONT) {
    SDL_Log("Failed to load '%s'\n", FONTPATH);
  } else {
    SDL_Log("'%s' Loaded\n", FONTPATH);
  }
  scoreTxt[0] = setProperties(setRect(10,10,175,50), FONT, "00000000");
  scoreTxt[1] = setProperties(setRect(10+180, 30, 50, 20), FONT, "x1.0");

  inGameScreen = loadTexture(window, INGAMESCREEN_PATH);
  startScreen  = loadTexture(window, STARTSCREEN_PATH);

  startScreenTxt[0] = setProperties(setRect(WINDOW_WIDTH/2-350/2, 100, 350, 75), FONT, "ChickRun");
  startScreenTxt[1] = setProperties(setRect(WINDOW_WIDTH/2-350/2, 325, 350, 20), FONT, "Press SPACE to start the game");

  gameOverTxt = setProperties(setRect(WINDOW_WIDTH/2-450/2, 100, 450, 75), FONT, "Press Escape to exit the game");

  loadTextTexture(window, startScreenTxt[0]);
  loadTextTexture(window, startScreenTxt[1]);
}

void updateIngameUI(Window* window, Player* player) {
  snprintf(scoreTxt[0]->txt, MAXLEN, "%08lu", (u64)player->score);
  snprintf(scoreTxt[1]->txt, MAXLEN, "x%.1f", player->scoreMultiplier);
  loadTextTexture(window, scoreTxt[0]);
  loadTextTexture(window, scoreTxt[1]);
}

void renderIngameUI(Window* window) {
  SDL_SetRenderDrawColor(window->renderer, 255,255,255,255);
  SDL_RenderCopy(window->renderer, inGameScreen, NULL, NULL);
  SDL_RenderCopy(window->renderer, scoreTxt[0]->texture, NULL, &scoreTxt[0]->dst);
  SDL_RenderCopy(window->renderer, scoreTxt[1]->texture, NULL, &scoreTxt[1]->dst);

}

void renderStartScreenUI(Window* window) {
  SDL_RenderCopy(window->renderer, startScreen, NULL, NULL);
  SDL_RenderCopy(window->renderer, startScreenTxt[0]->texture, NULL, &startScreenTxt[0]->dst); 
  SDL_RenderCopy(window->renderer, startScreenTxt[1]->texture, NULL, &startScreenTxt[1]->dst); 
}

void renderGameOver(Window* window) {
  loadTextTexture(window, gameOverTxt);
  SDL_RenderCopy(window->renderer, gameOverTxt->texture, NULL, &gameOverTxt->dst);
}

void destroyStartScreen(void) {
  DEBUGTXT("startScreen destroyed!\n");
  SDL_DestroyTexture(startScreen);

  DEBUGTXT("startScreenTxt[0]->Texture destroyed!\n");
  SDL_DestroyTexture(startScreenTxt[0]->texture);

  DEBUGTXT("startScreenTxt[1]->Texture destroyed!\n");
  SDL_DestroyTexture(startScreenTxt[1]->texture);

  DEBUGTXT("StartTxt[0] Freed!\n");
  free(startScreenTxt[0]);
  startScreenTxt[0] = NULL;

  DEBUGTXT("StartTxt[1] Freed!\n");
  free(startScreenTxt[1]);
  startScreenTxt[1] = NULL;
}

void destroyUI(void) {
  DEBUGTXT("inGameScreen destroyed!\n");
  SDL_DestroyTexture(inGameScreen);

  DEBUGTXT("scoreTxt[0]->Texture destroyed!\n");
  SDL_DestroyTexture(scoreTxt[0]->texture);

  DEBUGTXT("scoreTxt[1]->Texture destroyed!\n");
  SDL_DestroyTexture(scoreTxt[1]->texture);

  DEBUGTXT("ScoreTxt[0] Freed!\n");
  free(scoreTxt[0]);
  scoreTxt[0] = NULL;

  DEBUGTXT("ScoreTxt[1] Freed!\n");
  free(scoreTxt[1]);
  scoreTxt[1] = NULL;

  DEBUGTXT("gameOverTxt Freed!\n");
  free(gameOverTxt);
  gameOverTxt = NULL;

  DEBUGTXT("Close Font!\n");
  TTF_CloseFont(FONT);

  DEBUGTXT("TTF Quit!\n");
  TTF_Quit();
}
