#ifndef CIRCLE_CPP
#define CIRCLE_CPP

Circle::Circle(SDL_Renderer *renderer, int screenWidth, int screenHeight, const char *filePath) : 
m_yDirection {UP}, m_xDirection {RIGHT}, m_screenWidth{screenWidth}, m_screenHeight{screenHeight}{
  /* creating texture */ 
  SDL_Surface *tempSurface = IMG_Load(filePath); 
  if(tempSurface)
    m_texture = SDL_CreateTextureFromSurface(renderer, tempSurface); 
  SDL_FreeSurface(tempSurface); 
  restart();
  m_leftScore = 0; 
  m_rightScore = 0;
  m_wav = Mix_LoadWAV("assets/collide.wav");
}

Circle::~Circle() {
  if(m_texture)
    SDL_DestroyTexture(m_texture); 
  if(m_wav)
    Mix_FreeChunk(m_wav); 
}

/* motion of the circle */ 
void Circle::motion() {
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
    playSound(); 
  }
  if (m_rect.y > (m_screenHeight - m_rect.h)) {
    m_rect.y = m_screenHeight - m_rect.h; 
    m_yDirection = UP; 
    playSound();
  }
}

/* initial position */ 
void Circle::restart() {
  m_rect = {m_screenWidth/2, m_screenHeight/2, 20, 20}; 
}

/* set horizontal direction */ 
void Circle::setXDirection(X_Direction direction) {
  m_xDirection = direction; 
}

/* playing the wav file */ 
void Circle::playSound() {
  Mix_PlayChannel(1, m_wav, 0); 
}

#endif // CIRCLE_CPP