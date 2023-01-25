/* constructor */ 
Window::Window (const char* title, int width, int height) {
  m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0); 
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 
} 

/* set render draw color */ 
void Window::setDrawColor(SDL_Color color) {
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a); 
}

/* clear the window renderer */ 
void Window::clear() {
  SDL_RenderClear(m_renderer); 
}

/* update the window renderer */ 
void Window::update() {
  SDL_RenderPresent(m_renderer); 
}

/* render texture */ 
void Window::renderTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination) {
  SDL_RenderCopy(m_renderer, texture, source, destination); 
} 

/* render paddle */ 
void Window::render(Paddle& paddle) {
  SDL_RenderFillRect(m_renderer, &(paddle.m_rect)); 
}

/* render Circle */ 
void Window::render(Circle& circle) {
  SDL_RenderCopy(m_renderer, circle.m_texture, nullptr, &(circle.m_rect)); 
}

/* render Score */ 
void Window::render(Score& score) {
  SDL_Rect destination; 
  destination = {
    score.m_middle - (((int)((score.m_text)->getText()).length()) * CHAR_WIDTH) / 2,
    10, 
    CHAR_WIDTH * ((int)(score.m_text->getText()).size()), 
    CHAR_HEIGHT 
  }; 
  SDL_RenderCopy(m_renderer, score.m_text->getTexture(), nullptr, &destination); 
}