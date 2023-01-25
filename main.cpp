#include "SDL.h"
#include "Game.h"

/* main program */ 
int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO); 
  
  Game pongGame{400, 400}; 
  pongGame.loop(); 

  /* free allocated memory */ 
  SDL_Quit(); 
  return 0; 
}