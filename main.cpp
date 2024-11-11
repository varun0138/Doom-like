#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"

const unsigned int WINDOW_WIDTH = 1000;
const unsigned int WINDOW_HEIGHT = 700;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "", sf::Style::Close | sf::Style::Titlebar);


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

        window.clear();


        window.display();
    }

}