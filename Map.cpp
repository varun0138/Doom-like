#include "Map.hpp"

#include <fstream>

Map::Map() 
    : Map(sf::Vector2f(0.0f, 0.0f), 10, 15, 20.0f) {}

Map::Map(const sf::Vector2f& pos, unsigned int rows, unsigned int cols, float cellSize) 
    : m_pos(pos), m_rows(rows), m_cols(cols), m_cellSize(cellSize), m_grid(m_rows, std::vector<State>(m_cols, EMPTY)) {}

void Map::loadMap(const std::string& path) {
    std::ifstream file(path);

    file >> m_rows >> m_cols;
    m_grid = std::vector<std::vector<State>>(m_rows, std::vector<State>(m_cols, EMPTY));

    for(unsigned int row = 0; row < m_rows; row++) {
        for(unsigned int col = 0; col < m_cols; col++) {
            unsigned int value;
            file >> value;
            m_grid[row][col] = (State)value;
        }
    }

    file.close();
}

void Map::setPosition(const sf::Vector2f& pos) {
    m_pos = pos;
}

void Map::setCellSize(float cellSize) {
    m_cellSize = cellSize;
}

void Map::draw(sf::RenderTarget& target) {
    for(unsigned int row = 0; row < m_rows; row++) {
        for(unsigned int col = 0; col < m_cols; col++) {
            m_cell.setPosition(sf::Vector2f(col * m_cellSize + m_pos.x, row * m_cellSize + m_pos.y));
            m_cell.setSize(sf::Vector2f(m_cellSize - 1, m_cellSize - 1));

            switch(m_grid[row][col]) {
                case EMPTY: m_cell.setFillColor(sf::Color::Black); break;
                case WALL:  m_cell.setFillColor(sf::Color::White); break;
                default: break;
            }

            target.draw(m_cell);
        }
    }
}