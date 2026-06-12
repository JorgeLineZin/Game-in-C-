#include "Game.hpp"

Game::Game()
    : m_window(sf::VideoMode({1024, 768}), "SFML works!"),
      m_player(50.f, sf::Color::Green,
               sf::Vector2f(m_window.getSize().x / 2.f,
                            m_window.getSize().y / 2.f)) {}

void Game::run() {
  while (m_window.isOpen()) {
    sf::Time dt = m_clock.restart();
    processEvents();
    update(dt.asSeconds());
    render();
  }
}

void Game::processEvents() {
  while (const std::optional event = m_window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      m_window.close();
    // Outros eventos (tecla única, redimensionamento etc.)
  }
}

void Game::update(float deltaTime) {
  m_player.handleInput(deltaTime);
  m_player.update(deltaTime);
}

void Game::render() {
  m_window.clear();
  m_player.draw(m_window);
  m_window.display();
}
