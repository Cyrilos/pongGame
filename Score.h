#ifndef SCORE_H
  #define SCORE_H

#include "SDL.h"
#include "Text.h"

#define CHAR_WIDTH 30
#define CHAR_HEIGHT 80

class Score {
private:
  SDL_Rect m_rect; 
  Text    *m_text; 
  int      m_middle; // middle x position for centering the score

public:
  friend class Window; 

  Score(SDL_Renderer* renderer, int middleX) : m_middle {middleX} {
    m_text = new Text(renderer, "0", {255, 255, 255, 255});
  }

  ~Score() {
    if(m_text)
      delete m_text; 
  }

  /* updating the text of the score if necessary */ 
  void ifUpdate(int score) {
    if(m_text->getText() != (std::to_string(score)))
      m_text->setText(std::to_string(score)); 
  }
}; 

#endif // SCORE_H