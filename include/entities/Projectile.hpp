#pragma once

#include <SFML/Graphics.hpp>

class Projectile
{
public:
    Projectile(const sf::Vector2f &position, const sf::Vector2f &direction,
               float speed, float radius = 5.f);

    void update(float deltaTime);
    void draw(sf::RenderWindow &window) const;

    bool isOutOfBounds(const sf::Vector2u &windowSize) const;
    bool intersects(const sf::CircleShape &other) const;
    sf::Vector2f getPosition() const;
    float getRadius() const;

private:
    sf::CircleShape m_shape;
    sf::Vector2f m_velocity;
};
