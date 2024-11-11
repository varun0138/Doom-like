#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>

const float PI = 3.14159265358979323846;  

class Player {
private:
    sf::CircleShape m_player;

    sf::Vector2f m_pos;
    int m_turnDirection = 0; // -1 if left, +1 if right
    int m_walkDirection = 0; // -1 if back, +1 if front
    float m_rotationAngle = PI / 2.0f;
    float m_moveSpeed;

    const float m_rotationSpeed = 2 * (PI / 180);

public:
    Player(const sf::Vector2f& pos, float moveSpeed);

    void setTurnDirection(int dir);
    void setWalkDirection(int dir);

    void update();
    
    void draw(sf::RenderTarget& target);
};