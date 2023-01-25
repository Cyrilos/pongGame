#ifndef PADDLE_CPP
  #define PADDLE_CPP

Paddle::Paddle(int screenWidth, int screenHeight, X_Direction align) : 
m_screeWidth{screenWidth}, m_screeHeight{screenHeight}, m_direction{UP} {
  m_rect = {
    (align == LEFT)? 0 : screenWidth - PADDLE_WIDTH, 
    (screenHeight / 2) - (PADDLE_HEIGHT / 2),
    PADDLE_WIDTH, 
    PADDLE_HEIGHT
  }; 
}

/* move up the paddle */ 
void Paddle::up() {
  m_rect.y -= VELOCITY_Y; 
  if(m_rect.y < 0)
    m_rect.y = 0; 
}

/* move down the paddle */ 
void Paddle::down() {
  m_rect.y += VELOCITY_Y; 
  if(m_rect.y > (m_screeHeight - m_rect.h))
    m_rect.y = m_screeHeight - m_rect.h; 
}

/* set the position of the paddle */ 
void Paddle::setPosition(int y) {
  if((y > 0) && (y < m_screeHeight - m_rect.h))
      m_rect.y = y; 
}

#endif // PADDLE_CPP