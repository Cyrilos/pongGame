#ifndef GAME_CPP
  #define GAME_CPP

Game::Game(int width, int height) : m_runGame{true} {
  m_window = new Window("Pong game", width, height); 
  m_leftPaddle = new Paddle(width, height, LEFT); 
  m_rightPaddle = new Paddle(width, height, RIGHT); 
  m_circle = new Circle(m_window->getRenderer(), width, height, "assets/ball.png"); 

  /* creating score object */ 
  m_leftScore = new Score(m_window->getRenderer(), (0 + (width / 2)) / 2); 
  m_rightScore = new Score(m_window->getRenderer(), ((width / 2) + (width)) / 2);
}

Game::~Game() {
  if(m_leftPaddle)
    delete m_leftPaddle; 
  if(m_rightPaddle)
    delete m_rightPaddle; 
  if(m_circle)
    delete m_circle; 
  if(m_leftScore)
    delete m_leftScore; 
  if(m_rightScore)
    delete m_rightScore;
  if(m_window)
    delete m_window; 
}

/* game loop */ 
void Game::loop() {
  while(m_runGame) {
    SDL_PollEvent(&m_event); 

    /* quit the game */ 
    if(m_event.type == SDL_QUIT)
      onQuit();
    /* keyboard event */ 
    else if(m_event.type == SDL_KEYDOWN) {
      switch(m_event.key.keysym.sym) {
        case SDLK_UP: 
          onBtnUp(); 
          break; 
        case SDLK_DOWN:
          onBtnDown(); 
          break; 
        default:;
      }
    }
    m_circle->motion();
    moveLeftPaddle();
    detectCollision();
    ifUpdateScore();
    renderObject();
    SDL_Delay(SLEEP); 
  }
}

/* rendering game object */ 
void Game::renderObject() {
  m_window->setDrawColor({45, 42, 46, 255}); 
  m_window->clear(); 
  m_window->setDrawColor({255, 255, 255, 255}); 
  m_window->render(*m_leftPaddle);
  m_window->render(*m_rightPaddle); 
  m_window->render(*m_circle); 
  m_window->render(*m_leftScore); 
  m_window->render(*m_rightScore); 
  m_window->update();
}

/* quit event */ 
void Game::onQuit() {
  m_runGame = false; 
}

/* up arrow button event */ 
void Game::onBtnUp() {
  m_rightPaddle->up(); 
} 

/* down arrow button event */ 
void Game::onBtnDown() {
  m_rightPaddle->down(); 
} 

/* collision detector */ 
void Game::detectCollision() {
  if(SDL_HasIntersection(&(m_circle->m_rect), &(m_leftPaddle->m_rect))) {
    m_circle->playSound(); 
    m_circle->setXDirection(RIGHT); 
  }
  if(SDL_HasIntersection(&(m_circle->m_rect), &(m_rightPaddle->m_rect))) {
    m_circle->playSound(); 
    m_circle->setXDirection(LEFT);
  }
}

/* move left paddle */ 
void Game::moveLeftPaddle() {
  if(m_circle->m_xDirection == LEFT) {
    SDL_Point newPosition; 
    SDL_Point linePoint = {
      (m_circle->m_rect.x) + ((int) m_circle->m_xDirection) * CIRCLE_X_VELOCITY, 
      (m_circle->m_rect.y) + ((int) m_circle->m_yDirection) * CIRCLE_Y_VELOCITY 
    };
    int a = (linePoint.y - m_circle->m_rect.y) / (linePoint.x - m_circle->m_rect.x); 
    int b = linePoint.y - a * linePoint.x; 
    m_leftPaddle->setPosition(b - (m_leftPaddle->m_rect.h / 2));
  }
}

/* updating score if necessary */ 
void Game::ifUpdateScore() {
  m_leftScore->ifUpdate(m_circle->m_leftScore);
  m_rightScore->ifUpdate(m_circle->m_rightScore); 
}

#endif // GAME_CPP