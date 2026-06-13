#include "core/Game.hpp"
#include <iostream>

Game::Game()
    : m_window(sf::VideoMode({1024, 768}), "SFML works!"),
      m_player(
          20.f, sf::Color::Green,
          sf::Vector2f(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f)),
      m_showDebug(false), m_debugFont(), m_debugText(m_debugFont)
{
  if (!m_debugFont.openFromFile("../assets/fonts/LiberationSans-Regular.ttf"))
  {
    std::cerr << "Erro: Fonte 'LiberationSans-Regular.ttf' não encontrada!"
              << std::endl;
  }
  m_debugText.setCharacterSize(18);
  m_debugText.setFillColor(sf::Color::White);
  m_debugText.setPosition({10.f, 10.f});
}

void Game::run()
{
  while (m_window.isOpen())
  {
    sf::Time dt = m_clock.restart();
    processEvents();
    update(dt.asSeconds());
    render();
  }
}

void Game::processEvents()
{
  while (const std::optional event = m_window.pollEvent())
  {
    if (event->is<sf::Event::Closed>())
      m_window.close();

    // Alternar debug ao pressionar P
    if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
      if (keyPressed->code == sf::Keyboard::Key::P)
      {
        m_showDebug = !m_showDebug;
      }
    }
  }
}

void Game::update(float deltaTime)
{
  m_player.handleInput(deltaTime);
  m_player.update(deltaTime, m_window.getSize());
}

namespace
{
  void drawHitbox(sf::RenderWindow &window, const sf::Vector2f &position,
                  float radius, sf::Color color = sf::Color::Red)
  {
    sf::CircleShape hitbox(radius);
    hitbox.setPosition(position);
    hitbox.setOrigin({radius, radius});
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(color);
    hitbox.setOutlineThickness(2.f);
    window.draw(hitbox);
  }
} // namespace

void Game::render()
{
  m_window.clear();

  m_player.draw(m_window);
  m_player.drawProjectiles(m_window);

  // Painel de debug
  if (m_showDebug)
  {
    sf::Vector2f pos = m_player.getPosition();
    sf::Vector2f vel = m_player.getRealVelocity();

    std::string debugStr = "=== DEBUG ===\n";
    debugStr += "Posicao: (" + std::to_string(pos.x) + ", " +
                std::to_string(pos.y) + ")\n";
    debugStr += "Velocidade: (" + std::to_string(vel.x) + ", " +
                std::to_string(vel.y) + ") px/s\n";
    debugStr += "Velocidade (magnitude): " +
                std::to_string(std::sqrt(vel.x * vel.x + vel.y * vel.y)) +
                " px/s\n";
    debugStr += "Projeteis: " + std::to_string(m_player.getProjectiles().size());

    m_debugText.setString(debugStr);

    sf::FloatRect textBounds = m_debugText.getLocalBounds();
    sf::RectangleShape background(
        sf::Vector2f(textBounds.size.x + 20, textBounds.size.y + 20));
    background.setFillColor(sf::Color(0, 0, 0, 180));
    background.setPosition({5.f, 5.f});
    m_window.draw(background);

    m_window.draw(m_debugText);

    drawHitbox(m_window, m_player.getPosition(), m_player.getRadius(),
               sf::Color::Red);

    for (const auto &projectile : m_player.getProjectiles())
    {
      drawHitbox(m_window, projectile.getPosition(), projectile.getRadius(),
                 sf::Color::Yellow);
    }
  }

  m_window.display();
}
