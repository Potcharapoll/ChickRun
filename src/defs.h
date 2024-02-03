#ifndef DEFS_H
#define DEFS_H
#define PLATFORM_PATH         "res/gfx/platform.png"
#define PLAYER_PATH           "res/gfx/chicken.png"
#define SINGLE_OBSTACLE_PATH  "res/gfx/singleObstacle.png"
#define DOUBLE_OBSTACLE_PATH  "res/gfx/doubleObstacle.png"
#define STARTSCREEN_PATH      "res/gfx/StartGameBG.png"
#define INGAMESCREEN_PATH     "res/gfx/ingameBG.png"
#define FONTPATH              "res/fonts/8bitOperatorPlus8-Regular.ttf"
#define FONTSIZE              32
#define MAXLEN                50
#define BLOCKSIZE             16
#define SCALE                 64
#define GRAVITY               0.24F
#define JUMP_TIME             0.01F
#define JUMP_FORCE            2.50f
#define WINDOW_WIDTH          640
#define WINDOW_HEIGHT         480
#define OBSTACLE_POSY         WINDOW_HEIGHT-100-(SCALE*2)
#define PLATFORM_POSY         WINDOW_HEIGHT-100-SCALE

#ifndef DEBUG
  #define DEBUGTXT(...)
#elif DEBUG
  #define DEBUGTXT(...) SDL_Log(__VA_ARGS__);
#endif

#endif
