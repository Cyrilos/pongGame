#include "SDL.h"
#include "SDL_mixer.h"
#include "Game.h"

/* main program */ 
int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO); 
  Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

  Game pongGame{400, 400}; 
  pongGame.loop(); 

  /* free allocated memory */ 
  Mix_CloseAudio(); 
  SDL_Quit(); 
  return 0; 
}