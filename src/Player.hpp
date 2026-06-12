#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
  Player(float radius, sf::Color color, const sf::Vector2f &startPosition);
  void handleInput(float deltaTime);
  void update(float deltaTime);
  void draw(sf::RenderWindow &window) const;
  void setPosition(const sf::Vector2f &position);
  sf::Vector2f getPosition() const;

private:
  sf::CircleShape m_shape;
  sf::Vector2f m_velocity;
  float m_speed;
  float m_speedMultiplier;
};
