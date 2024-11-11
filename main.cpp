#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"
#include "Player.hpp"

const unsigned int WINDOW_WIDTH = 1000;
const unsigned int WINDOW_HEIGHT = 700;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(50);

    Map map(sf::Vector2f(10.0f, 100.0f), 10, 15, 20);
    map.loadMap("map2.txt");
    map.setCellSize(40.0f);

    Player player(sf::Vector2f(100.0f, 100.0f), 2.0f);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::W)      { player.setWalkDirection(-1); }
                    else if(event.key.code == sf::Keyboard::S) { player.setWalkDirection(1); }
                    else if(event.key.code == sf::Keyboard::A) { player.setTurnDirection(-1); }
                    else if(event.key.code == sf::Keyboard::D) { player.setTurnDirection(1); }
                    break;

                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::W)      { player.setWalkDirection(0); }
                    else if(event.key.code == sf::Keyboard::S) { player.setWalkDirection(0); }
                    else if(event.key.code == sf::Keyboard::A) { player.setTurnDirection(0); }
                    else if(event.key.code == sf::Keyboard::D) { player.setTurnDirection(0); }
                    break;

                default:
                    break;
            }
        }

        window.clear(sf::Color(198, 212, 140));

        map.draw(window);
        player.draw(window);

        window.display();
    }

}