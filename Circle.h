#ifndef CIRCLE_H
  #define CIRCLE_H

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"

#define CIRCLE_X_VELOCITY 10
#define CIRCLE_Y_VELOCITY 15

class Circle {
private:
  int m_screenWidth; 
  int m_screenHeight; 
  int m_leftScore; 
  int m_rightScore;
  SDL_Rect m_rect; 
  SDL_Texture *m_texture; 
  Y_Direction m_yDirection; 
  X_Direction m_xDirection; 
  Mix_Chunk  *m_wav; // sound 

public:
  friend class Window;
  friend class Game; 

  Circle(SDL_Renderer *renderer, int screenWidth, int screenHeight, const char *filePath);

  ~Circle();

  /* motion of the circle */ 
  void motion();

  /* initial position */ 
  void restart();

  /* set horizontal direction */ 
  void setXDirection(X_Direction direction);

  /* playing the wav file */ 
  void playSound();
};

#ifndef CIRCLE_CPP
#include "Circle.cpp"
#endif // CIRCLE_CPP
#endif // CIRCLE_H