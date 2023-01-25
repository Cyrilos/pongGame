#ifndef CIRCLE_H
  #define CIRCLE_H

#include "SDL.h"
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

public:
  friend class Window;
  friend class Game; 

  Circle(SDL_Renderer *renderer, int screenWidth, int screenHeight, const char *filePath) : 
  m_yDirection {UP}, m_xDirection {RIGHT}, m_screenWidth{screenWidth}, m_screenHeight{screenHeight}{
    /* creating texture */ 
    SDL_Surface *tempSurface = IMG_Load(filePath); 
    if(tempSurface)
      m_texture = SDL_CreateTextureFromSurface(renderer, tempSurface); 
    SDL_FreeSurface(tempSurface); 
    restart();
    m_leftScore = 0; 
    m_rightScore = 0;
  }

  ~Circle() {
    if(m_texture)
      SDL_DestroyTexture(m_texture); 
  }

  /* motion of the circle */ 
  void motion() {
    m_rect.x += (CIRCLE_X_VELOCITY) * ((int) m_xDirection);
    m_rect.y += (CIRCLE_Y_VELOCITY) * ((int) m_yDirection); 
    if(m_rect.x < 0) {
      m_rightScore++; 
      restart();
    }
    if(m_rect.x > (m_screenWidth - m_rect.w)) {
      m_leftScore++;
      restart();
    }

    if(m_rect.y < 0) {
      m_rect.y = 0; 
      m_yDirection = DOWN; 
    }
    if (m_rect.y > (m_screenHeight - m_rect.h)) {
      m_rect.y = m_screenHeight - m_rect.h; 
      m_yDirection = UP; 
    }
  }

  /* initial position */ 
  void restart() {
    m_rect = {m_screenWidth/2, m_screenHeight/2, 20, 20}; 
  }

  /* set horizontal direction */ 
  void setXDirection(X_Direction direction) {
    m_xDirection = direction; 
  }

};

#endif // CIRCLE_H