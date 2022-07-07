#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "SFMLScreen.h"

void intro(){
    std::cout<<"AJG XXXX96"<<std::endl;
}

int main(){
    intro();
   // Card karta;
    MainMenu main;
    GameCtrl game;

    EndScreen end;

    sf::RenderWindow window(sf::VideoMode(1600, 720), "Memory Game");
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        // check all the windows events that were triggered

        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();

            if (main.active){
                if (event.type == sf::Event::MouseButtonPressed && main.button1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    main.active = false;
                    game.active = true;
                }

                if (event.type == sf::Event::MouseButtonPressed && main.button2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                    window.close();
                }
            }
            else if (game.active){
                for(int i = 0; i < game.cards.size(); i++){
                    if (event.type == sf::Event::MouseButtonPressed && game.cards[i].body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){

                        game.cards[i].isOpen = true;
                        game.cards[game.cards[i].pairindex].body.setFillColor(sf::Color::Green);
                        game.gameLogic(i);
                    }
                }
            }
            else if (end.active){
                if(event.type == sf::Event::MouseButtonPressed){
                    end.active = false;
                    main.active = true;
                }
            }
        }

        if (game.active){
            int isWin = 0;
            for(int i = 0; i < game.cards.size(); i++) if (game.cards[i].isOk) isWin++;
            if (isWin == 48){
                game.active = false;
                end.active = true;
                // game.resetGame();
            }
        }

        window.clear(sf::Color::Black);
        if (main.active==1) main.drawScreen(window);
        else if (game.active) game.drawScreen(window);
        else if (end.active) end.drawScreen(window);


        window.display();
    }
    return 0;
}
