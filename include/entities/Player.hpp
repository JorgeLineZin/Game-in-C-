#pragma once
#include "entities/Projectile.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
public:
  Player(float radius, sf::Color color, const sf::Vector2f &startPosition);
  void handleInput(float deltaTime);
  void update(float deltaTime, const sf::Vector2u &windowSize);
  void draw(sf::RenderWindow &window) const;
  void setPosition(const sf::Vector2f &position);
  sf::Vector2f getPosition() const;
  sf::Vector2f getRealVelocity() const;
  float getRadius() const;
  void shoot();
  void updateProjectiles(float deltaTime, const sf::Vector2u &windowSize);
  void drawProjectiles(sf::RenderWindow &window) const;
  const std::vector<Projectile> &getProjectiles() const;

private:
  sf::CircleShape m_shape;
  sf::Vector2f m_velocity;
  float m_speed;
  float m_speedMultiplier;
  float m_fireCooldown;
  std::vector<Projectile> m_projectiles;
};
