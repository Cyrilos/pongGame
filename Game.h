#ifndef GAME_H
  #define GAME_H

#include "SDL.h"
#include "Paddle.h"
#include "Circle.h"
#include "Score.h"
#include "Window.h"
#include "Utils.h"

#define SLEEP 60

class Game {
private:
  Window    *m_window; 
  Paddle    *m_leftPaddle;
  Paddle    *m_rightPaddle; 
  Circle    *m_circle; 
  Score     *m_leftScore;
  Score     *m_rightScore; 
  SDL_Event  m_event; 
  bool       m_runGame; 

public:
  Game(int width, int height);

  ~Game();

  /* game loop */ 
  void loop();

private: 
  /* rendering game object */ 
  void renderObject();

  /* quit event */ 
  void onQuit();

  /* up arrow button event */ 
  void onBtnUp(); 

  /* down arrow button event */ 
  void onBtnDown(); 

  /* collision detector */ 
  void detectCollision();

  /* move left paddle */ 
  void moveLeftPaddle();

  /* updating score if necessary */ 
  void ifUpdateScore();
};

#ifndef GAME_CPP
  #include "Game.cpp"
#endif // GAME_CPP

#endif // GAME_H