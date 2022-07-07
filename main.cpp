#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



int main(){



    sf::RenderWindow window(sf::VideoMode(1600, 720), "Memory Game");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        // check all the windows events that were triggered

        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();


        }



        window.clear(sf::Color::Black);


        window.display();
    }
    return 0;
}
