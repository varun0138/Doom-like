#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>

void drawLine(sf::RenderTarget& target, const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color) {
    sf::Vertex lines[2] = { sf::Vertex(start), sf::Vertex(end) };
    lines[0].color = lines[1].color = color; 

    target.draw(lines, 2, sf::Lines);
}