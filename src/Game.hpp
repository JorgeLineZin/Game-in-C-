#pragma once
#include "Player.hpp"
#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void run();

private:
  void processEvents();
  void update(float deltaTime);
  void render();

  sf::RenderWindow m_window;
  Player m_player;
  sf::Clock m_clock;
};
