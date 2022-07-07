#include "Card.h"
Card::Card(std::string dat){

    body.setSize({50, 50});

    text.setCharacterSize(30);text.setFillColor(sf::Color::Black);text.setPosition(5, 5);

    data = dat;
    text.setString(data);
}

Card::Card(){

    body.setSize({50, 50});

    text.setFillColor(sf::Color::Black);text.setCharacterSize(30);text.setPosition(5, 5);
}

void Card::setPos(int x, int y){

    body.setPosition(x, y);
    text.setPosition(x+5, y+5);
}

void Card::drawCard(sf::RenderWindow &window){

    window.draw(body);
    if (isOpen) window.draw(text);
}
