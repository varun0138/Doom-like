#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"

const unsigned int WINDOW_WIDTH = 1000;
const unsigned int WINDOW_HEIGHT = 700;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "", sf::Style::Close | sf::Style::Titlebar);

    Map map(sf::Vector2f(10.0f, 100.0f), 10, 15, 20);
    map.loadMap("map1.txt");
    map.setCellSize(40.0f);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear(sf::Color(198, 212, 140));

        map.draw(window);

        window.display();
    }

}