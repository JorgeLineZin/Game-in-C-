#pragma once
#include "entities/Player.hpp"
#include <SFML/Graphics.hpp>

class Game
{
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
  sf::Clock m_fireClock;

  // Debug
  bool m_showDebug;
  sf::Font m_debugFont;
  sf::Text m_debugText;
};
