#include "entities/Projectile.hpp"

#include <cmath>

Projectile::Projectile(const sf::Vector2f &position,
                       const sf::Vector2f &direction, float speed,
                       float radius)
    : m_shape(radius), m_velocity(direction * speed)
{
    m_shape.setFillColor(sf::Color::Yellow);
    m_shape.setOrigin({radius, radius});
    m_shape.setPosition(position);
}

void Projectile::update(float deltaTime) { m_shape.move(m_velocity * deltaTime); }

void Projectile::draw(sf::RenderWindow &window) const { window.draw(m_shape); }

bool Projectile::isOutOfBounds(const sf::Vector2u &windowSize) const
{
    const sf::Vector2f pos = m_shape.getPosition();
    return pos.x < -20.f || pos.x > static_cast<float>(windowSize.x) + 20.f ||
           pos.y < -20.f || pos.y > static_cast<float>(windowSize.y) + 20.f;
}

bool Projectile::intersects(const sf::CircleShape &other) const
{
    const sf::Vector2f a = m_shape.getPosition();
    const sf::Vector2f b = other.getPosition();
    const float distance = std::hypot(a.x - b.x, a.y - b.y);
    return distance < m_shape.getRadius() + other.getRadius();
}

sf::Vector2f Projectile::getPosition() const { return m_shape.getPosition(); }

float Projectile::getRadius() const { return m_shape.getRadius(); }
