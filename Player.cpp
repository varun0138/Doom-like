#include "Player.hpp"
#include "Line.hpp"

#include <cmath>

Player::Player(const sf::Vector2f& pos, float moveSpeed) 
    : m_pos(pos), m_moveSpeed(moveSpeed) {}

void Player::setTurnDirection(int dir) {
    m_turnDirection = dir;
}

void Player::setWalkDirection(int dir) {
    m_walkDirection = dir;
}

void Player::update() {
    m_rotationAngle += m_turnDirection * m_rotationSpeed;

    float moveStep = m_walkDirection * m_moveSpeed;
    m_pos = { m_pos.x + std::cos(m_rotationAngle) * moveStep, m_pos.y + std::sin(m_rotationAngle) * moveStep };
}

void Player::draw(sf::RenderTarget& target) {
    update();

    m_player.setRadius(5.0f);
    m_player.setOrigin(sf::Vector2f(m_player.getRadius(), m_player.getRadius()));
    m_player.setFillColor(sf::Color::Red);
    m_player.setPosition(m_pos);

    target.draw(m_player);

    drawLine(target, m_pos, m_pos + sf::Vector2f(std::cos(m_rotationAngle) * 30, std::sin(m_rotationAngle) * 30), sf::Color::Red);
}