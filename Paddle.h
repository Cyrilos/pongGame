#ifndef PADDLE_H
  #define PADDLE_H

#include "SDL.h"
#include "Utils.h"

#define VELOCITY_Y 20
#define PADDLE_WIDTH 15
#define PADDLE_HEIGHT 80

class Paddle {
private:
  int         m_screeHeight; 
  int         m_screeWidth; 
  SDL_Rect    m_rect; 
  Y_Direction m_direction;  

public:
  friend class Window; 
  friend class Game; 

  Paddle(int screenWidth, int screenHeight, X_Direction align); 

  /* move up the paddle */ 
  void up(); 

  /* move down the paddle */ 
  void down(); 

  /* set the position of the paddle */ 
  void setPosition(int y);
};  

#ifndef PADDLE_CPP
  #include "Paddle.cpp"
#endif // PADDLE_CPP

#endif // PADDLE_H