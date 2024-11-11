#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>

enum State: unsigned int {
    EMPTY = 0,
    WALL  = 1
};

class Map {
private:
    sf::RectangleShape m_cell;
    sf::Vector2f m_pos;
    unsigned int m_rows;
    unsigned int m_cols;
    float m_cellSize;

    std::vector<std::vector<State>> m_grid;

public:
    Map();
    Map(const sf::Vector2f& pos, unsigned int rows, unsigned int cols, float cellSize);
    
    void loadMap(const std::string& path);

    void setPosition(const sf::Vector2f& pos);
    void setCellSize(float cellSize);

    void draw(sf::RenderTarget& target);
};