#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Player::Player(float radius, sf::Color color, const sf::Vector2f &startPosition)
    : m_speed(200.f), m_speedMultiplier(1.0f) {
  m_shape.setRadius(radius);
  m_shape.setFillColor(color);
  m_shape.setOrigin({radius, radius});
  m_shape.setPosition(startPosition);
}

void Player::handleInput(float /*deltaTime*/) {
  m_velocity = {0.f, 0.f};

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    m_velocity.y -= 1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    m_velocity.y += 1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    m_velocity.x -= 1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    m_velocity.x += 1.f;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    m_velocity.y -= 1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    m_velocity.y += 1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    m_velocity.x -= 1.f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    m_velocity.x += 1.f;

  // Normaliza para que diagonais não fiquem mais rápidas
  if (m_velocity != sf::Vector2f(0.f, 0.f)) {
    float len =
        std::sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
    m_velocity /= len;
  }
}

void Player::update(float deltaTime) {
  float targetMultiplier =
      (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
          ? 2.0f
          : 1.0f;
  m_speedMultiplier +=
      (targetMultiplier - m_speedMultiplier) * 10.f * deltaTime;
  m_shape.move(m_velocity * m_speed * m_speedMultiplier * deltaTime);
}

void Player::draw(sf::RenderWindow &window) const { window.draw(m_shape); }

void Player::setPosition(const sf::Vector2f &position) {
  m_shape.setPosition(position);
}

sf::Vector2f Player::getPosition() const { return m_shape.getPosition(); }
